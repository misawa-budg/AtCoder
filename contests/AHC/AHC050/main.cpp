#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <numeric>
#include <array>
#include <tuple>

auto start_time = std::chrono::steady_clock::now();

double get_time() {
    auto now = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::duration<double>>(now - start_time).count();
}

struct Pos {
    int r, c;
    bool operator==(const Pos& other) const { return r == other.r && c == other.c; }
};

constexpr int N = 40;
constexpr int DR[] = {-1, 1, 0, 0};
constexpr int DC[] = {0, 0, -1, 1};
constexpr int BEAM_WIDTH = 10;

int M;
std::array<std::array<bool, N>, N> initial_is_rock;
std::vector<Pos> initial_empty_cells;

struct GameState {
    std::array<std::array<bool, N>, N> is_rock;
    std::array<std::array<std::array<Pos, 4>, N>, N> obstacle_pos;

    GameState() = default;

    void init() {
        is_rock = initial_is_rock;
        precompute_initial_obstacle_pos();
    }

    void precompute_initial_obstacle_pos() {
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                for (int d = 0; d < 4; ++d) {
                    int nr = r, nc = c;
                    while (true) {
                        nr += DR[d];
                        nc += DC[d];
                        if (nr < 0 || nr >= N || nc < 0 || nc >= N || is_rock[nr][nc]) {
                            obstacle_pos[r][c][d] = {nr, nc};
                            break;
                        }
                    }
                }
            }
        }
    }

    void place_rock(const Pos& p) {
        if (is_rock[p.r][p.c]) return;
        is_rock[p.r][p.c] = true;
        update_obstacle_pos(p);
    }

    void update_obstacle_pos(const Pos& new_rock_pos) {
        int r = new_rock_pos.r;
        int c = new_rock_pos.c;
        for (int i = r - 1; i >= 0 && !is_rock[i][c]; --i) obstacle_pos[i][c][1] = new_rock_pos;
        for (int i = r + 1; i < N && !is_rock[i][c]; ++i) obstacle_pos[i][c][0] = new_rock_pos;
        for (int j = c - 1; j >= 0 && !is_rock[r][j]; --j) obstacle_pos[r][j][3] = new_rock_pos;
        for (int j = c + 1; j < N && !is_rock[r][j]; ++j) obstacle_pos[r][j][2] = new_rock_pos;
    }

    Pos get_landing_pos(const Pos& start_pos, int dir) const {
        const Pos& obs_pos = obstacle_pos[start_pos.r][start_pos.c][dir];
        return {obs_pos.r - DR[dir], obs_pos.c - DC[dir]};
    }
};

struct BeamNode {
    std::vector<Pos> sequence;
    double score = 0.0;
    GameState state;
    std::array<std::array<double, N>, N> current_prob;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> M >> M;
    for (int i = 0; i < N; ++i) {
        std::string row;
        std::cin >> row;
        for (int j = 0; j < N; ++j) {
            if (row[j] == '#') {
                initial_is_rock[i][j] = true;
            } else {
                initial_is_rock[i][j] = false;
                initial_empty_cells.push_back({i, j});
            }
        }
    }

    int total_turns = initial_empty_cells.size();

    std::vector<BeamNode> beams;
    {
        BeamNode root;
        root.state.init();
        root.current_prob.fill({});
        double initial_p = 1.0 / total_turns;
        for (const auto& p : initial_empty_cells) {
            root.current_prob[p.r][p.c] = initial_p;
        }
        beams.push_back(std::move(root));
    }

    int beam_search_turns = std::min((int)total_turns, 200);

    for (int turn = 0; turn < beam_search_turns; ++turn) {
        if (get_time() > 1.5) {
            beam_search_turns = turn;
            break;
        }

        std::vector<std::tuple<double, int, Pos>> candidates;
        for (int i = 0; i < beams.size(); ++i) {
            const auto& beam = beams[i];

            std::array<std::array<double, N>, N> next_pos_prob{};
            for (const auto& p : initial_empty_cells) {
                if (beam.state.is_rock[p.r][p.c]) continue;
                if (beam.current_prob[p.r][p.c] > 1e-12) {
                    for (int d = 0; d < 4; ++d) {
                        Pos landing_pos = beam.state.get_landing_pos(p, d);
                        next_pos_prob[landing_pos.r][landing_pos.c] += beam.current_prob[p.r][p.c] * 0.25;
                    }
                }
            }

            for (const auto& p : initial_empty_cells) {
                if (!beam.state.is_rock[p.r][p.c]) {
                    double score = -next_pos_prob[p.r][p.c];
                    candidates.emplace_back(beam.score + score, i, p);
                }
            }
        }

        std::sort(candidates.begin(), candidates.end(), [](const auto& a, const auto& b) {
            return std::get<0>(a) > std::get<0>(b);
        });

        if (candidates.size() > BEAM_WIDTH) {
            candidates.resize(BEAM_WIDTH);
        }

        std::vector<BeamNode> next_beams;
        for(const auto& cand : candidates) {
            const auto& [score, parent_idx, move] = cand;

            BeamNode next_node;
            next_node.score = score;
            const auto& parent_beam = beams[parent_idx];

            next_node.sequence = parent_beam.sequence;
            next_node.sequence.push_back(move);

            next_node.state = parent_beam.state;
            next_node.state.place_rock(move);

            next_node.current_prob.fill({});
            std::array<std::array<double, N>, N> temp_next_pos_prob{};
            for(const auto& p : initial_empty_cells) {
                if(parent_beam.state.is_rock[p.r][p.c]) continue;
                if (parent_beam.current_prob[p.r][p.c] > 1e-12) {
                     for (int d = 0; d < 4; ++d) {
                        Pos landing_pos = parent_beam.state.get_landing_pos(p, d);
                        temp_next_pos_prob[landing_pos.r][landing_pos.c] += parent_beam.current_prob[p.r][p.c] * 0.25;
                    }
                }
            }
            next_node.current_prob = temp_next_pos_prob;
            next_node.current_prob[move.r][move.c] = 0;
            next_beams.push_back(std::move(next_node));
        }
        beams = std::move(next_beams);
        if (beams.empty()) {
            beam_search_turns = turn;
            break;
        }
    }

    std::vector<Pos> placement_order;
    BeamNode final_beam_state;

    if(beams.empty()){
        placement_order = initial_empty_cells;
        final_beam_state.state.init();
        final_beam_state.current_prob.fill({});
        double initial_p = 1.0 / total_turns;
        for (const auto& p : initial_empty_cells) {
            final_beam_state.current_prob[p.r][p.c] = initial_p;
        }
    } else {
        final_beam_state = std::move(beams[0]);
        placement_order = final_beam_state.sequence;
    }

    std::array<std::array<bool, N>, N> is_placed{};
    for(const auto& p : placement_order) is_placed[p.r][p.c] = true;

    for (int turn = beam_search_turns; turn < total_turns; ++turn) {
        std::array<std::array<double, N>, N> next_pos_prob{};
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                if (final_beam_state.current_prob[r][c] > 1e-12) {
                    for (int d = 0; d < 4; ++d) {
                        Pos landing_pos = final_beam_state.state.get_landing_pos({r, c}, d);
                        next_pos_prob[landing_pos.r][landing_pos.c] += final_beam_state.current_prob[r][c] * 0.25;
                    }
                }
            }
        }

        Pos best_pos = {-1, -1};
        double min_prob = 1e18;

        for (const auto& p : initial_empty_cells) {
            if (!is_placed[p.r][p.c]) {
                if (next_pos_prob[p.r][p.c] < min_prob) {
                    min_prob = next_pos_prob[p.r][p.c];
                    best_pos = p;
                }
            }
        }

        if(best_pos.r == -1) {
            for(const auto& p : initial_empty_cells) {
                if(!is_placed[p.r][p.c]) {
                    best_pos = p;
                    break;
                }
            }
        }

        placement_order.push_back(best_pos);
        is_placed[best_pos.r][best_pos.c] = true;
        final_beam_state.state.place_rock(best_pos);

        final_beam_state.current_prob = next_pos_prob;
        if(best_pos.r != -1) {
            final_beam_state.current_prob[best_pos.r][best_pos.c] = 0;
        }
    }

    for (const auto& p : placement_order) {
        std::cout << p.r << " " << p.c << std::endl;
    }

    return 0;
}
