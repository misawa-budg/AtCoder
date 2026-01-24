#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <string>
#include <chrono>
#include <random>
#include <map>

using namespace std;

const int N = 20;
const auto TIME_LIMIT = chrono::milliseconds(1950);
auto start_time = chrono::steady_clock::now();
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Box {
    int id;
    int r, c;
    int w, d;
    bool is_direct_candidate;
};

vector<Box> boxes;
vector<bool> is_delivered;
int total_delivered_count = 0;
pair<int, int> current_pos = {0, 0};
string result_actions;

int manhattanDistance(int r1, int c1, int r2, int c2) {
    return abs(r1 - r2) + abs(c1 - c2);
}

bool is_tour_valid(const vector<int>& tour_ids) {
    if (tour_ids.empty()) return true;
    size_t k = tour_ids.size();
    vector<pair<int, int>> positions;
    positions.push_back({0, 0});
    for (int id : tour_ids) positions.push_back({boxes[id].r, boxes[id].c});
    for (size_t i = 0; i < k; ++i) {
        long long weight_on_top = 0;
        for (size_t j = i + 1; j < k; ++j) weight_on_top += boxes[tour_ids[j]].w;
        if (weight_on_top == 0) continue;
        long long travel_distance = 0;
        for (size_t j = i + 1; j < k; ++j) travel_distance += manhattanDistance(positions[j].first, positions[j].second, positions[j + 1].first, positions[j + 1].second);
        travel_distance += manhattanDistance(positions[k].first, positions[k].second, 0, 0);
        if (weight_on_top * travel_distance > boxes[tour_ids[i]].d) return false;
    }
    return true;
}

long long calculate_tour_distance(const vector<int>& tour_ids) {
    if (tour_ids.empty()) return 0;
    long long total_dist = 0;
    pair<int, int> prev_pos = {0, 0};
    for (int box_id : tour_ids) {
        total_dist += manhattanDistance(prev_pos.first, prev_pos.second, boxes[box_id].r, boxes[box_id].c);
        prev_pos = {boxes[box_id].r, boxes[box_id].c};
    }
    total_dist += manhattanDistance(prev_pos.first, prev_pos.second, 0, 0);
    return total_dist;
}

void get_path_actions(pair<int, int>& start, const pair<int, int>& end) {
    int dr = end.first - start.first;
    int dc = end.second - start.second;
    if (dr > 0) result_actions += string(dr, 'D');
    if (dr < 0) result_actions += string(-dr, 'U');
    if (dc > 0) result_actions += string(dc, 'R');
    if (dc < 0) result_actions += string(-dc, 'L');
    start = end;
}

void execute_tour(const vector<int>& tour_ids) {
    if (tour_ids.empty()) return;
    pair<int, int> pos = {0, 0};
    for (int id : tour_ids) {
        get_path_actions(pos, {boxes[id].r, boxes[id].c});
        result_actions += '1';
    }
    get_path_actions(pos, {0, 0});
    for (int id : tour_ids) {
        if (!is_delivered[id]) {
            is_delivered[id] = true;
            total_delivered_count++;
        }
    }
}

void solve() {
    for (int i = 0; i < boxes.size(); ++i) {
        if (manhattanDistance(boxes[i].r, boxes[i].c, 0, 0) < 15) {
            boxes[i].is_direct_candidate = true;
        } else {
            boxes[i].is_direct_candidate = false;
        }
    }

    bool direct_phase_complete = false;
    while (total_delivered_count < boxes.size()) {
        if (chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start_time) > TIME_LIMIT) break;

        vector<int> candidates;
        if (!direct_phase_complete) {
            for (const auto& box : boxes) {
                if (!is_delivered[box.id] && box.is_direct_candidate) {
                    candidates.push_back(box.id);
                }
            }
            if (candidates.empty()) {
                direct_phase_complete = true;
                continue;
            }
        } else {
            for (const auto& box : boxes) {
                if (!is_delivered[box.id]) {
                    candidates.push_back(box.id);
                }
            }
        }
        if (candidates.empty()) break;

        sort(candidates.begin(), candidates.end(), [&](int a, int b) {
            return boxes[a].w > boxes[b].w;
        });

        vector<int> best_tour;
        {
            vector<int> current_tour;
            vector<bool> in_tour(boxes.size(), false);
            while (true) {
                int next_box_id = -1;
                double best_score = -1.0;
                for (int id : candidates) {
                    if (in_tour[id]) continue;
                    vector<int> temp_tour = current_tour;
                    temp_tour.push_back(id);
                    if (is_tour_valid(temp_tour)) {
                        pair<int, int> last_pos = current_tour.empty() ? make_pair(0,0) : make_pair(boxes[current_tour.back()].r, boxes[current_tour.back()].c);
                        double score = (double)boxes[id].w / (manhattanDistance(last_pos.first, last_pos.second, boxes[id].r, boxes[id].c) + 1.0);
                        if(score > best_score){
                            best_score = score;
                            next_box_id = id;
                        }
                    }
                }
                if (next_box_id != -1) {
                    current_tour.push_back(next_box_id);
                    in_tour[next_box_id] = true;
                } else {
                    break;
                }
            }
            best_tour = current_tour;
        }

        if (best_tour.empty()) {
             for (int id : candidates) {
                if (is_tour_valid({id})) {
                    best_tour.push_back(id);
                    break;
                }
            }
        }

        if(best_tour.empty()) break;

        execute_tour(best_tour);
    }
    for (char c : result_actions) {
        cout << c << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n_dummy; cin >> n_dummy;
    vector<vector<int>> weights(N, vector<int>(N));
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) cin >> weights[i][j];
    vector<vector<int>> strengths(N, vector<int>(N));
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) cin >> strengths[i][j];

    int id_counter = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == 0 && j == 0) continue;
            boxes.push_back({id_counter, i, j, weights[i][j], strengths[i][j], false});
            id_counter++;
        }
    }
    is_delivered.resize(boxes.size(), false);
    solve();
    return 0;
}
