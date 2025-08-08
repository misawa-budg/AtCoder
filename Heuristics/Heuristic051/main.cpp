#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

int sign(long long val) {
    if (val > 0) return 1;
    if (val < 0) return -1;
    return 0;
}

int orientation(Point a, Point b, Point c) {
    long long cross_product = (long long)(b.x - a.x) * (c.y - a.y) - (long long)(b.y - a.y) * (c.x - a.x);
    return sign(cross_product);
}

bool segments_intersect(Point p1, Point p2, Point q1, Point q2) {
    if (max(p1.x, p2.x) < min(q1.x, q2.x) ||
        max(q1.x, q2.x) < min(p1.x, p2.x) ||
        max(p1.y, p2.y) < min(q1.y, q2.y) ||
        max(q1.y, q2.y) < min(p1.y, p2.y)) {
        return false;
    }

    int o1 = orientation(p1, p2, q1);
    int o2 = orientation(p1, p2, q2);
    int o3 = orientation(q1, q2, p1);
    int o4 = orientation(q1, q2, p2);

    return (o1 * o2 <= 0) && (o3 * o4 <= 0);
}

bool has_intersection(const pair<Point, Point>& new_belt, const vector<pair<Point, Point>>& existing_belts) {
    for (const auto& old_belt : existing_belts) {
        if (new_belt.first == old_belt.first || new_belt.first == old_belt.second ||
            new_belt.second == old_belt.first || new_belt.second == old_belt.second) {
            continue;
        }
        if (segments_intersect(new_belt.first, new_belt.second, old_belt.first, old_belt.second)) {
            return true;
        }
    }
    return false;
}

vector<Point> d_pos_g;
vector<Point> s_pos_g;
vector<vector<double>> p_g;
int N_g, M_g, K_g;

vector<bool> s_pos_used_g;
vector<bool> d_pos_used_g;
vector<bool> garbage_assigned_g;

vector<pair<Point, Point>> belts_g;
vector<int> d_out;
struct SorterOutput { int k = -1, v1 = -1, v2 = -1; };
vector<SorterOutput> s_out;

struct BestSplit { int k = -1; double t = 0.5; };

struct AssignmentResult {
    double score = 0.0;
    vector<int> device_to_type; // size N_g, device index -> assigned type
};

// Forward declarations for functions used below
void dfs_propagate_to_devices(int garbage_type,
                              int node_id,
                              double prob,
                              vector<vector<double>>& device_reach_prob);
vector<int> hungarian_solve_min_cost(const vector<vector<double>>& cost);
int build_tree(Point parent_pos, const vector<int>& garbage_group);
void optimize_sorter_orientations(int entrance_target, chrono::steady_clock::time_point deadline);

AssignmentResult compute_best_assignment(int entrance_target) {
    vector<vector<double>> device_reach_prob(N_g, vector<double>(N_g, 0.0));
    if (entrance_target < N_g) {
        for (int g = 0; g < N_g; ++g) device_reach_prob[g][entrance_target] += 1.0;
    } else {
        for (int g = 0; g < N_g; ++g) dfs_propagate_to_devices(g, entrance_target, 1.0, device_reach_prob);
    }
    double max_val = 0.0;
    for (int i = 0; i < N_g; ++i) for (int j = 0; j < N_g; ++j) max_val = max(max_val, device_reach_prob[i][j]);
    vector<vector<double>> cost(N_g, vector<double>(N_g, 0.0));
    for (int i = 0; i < N_g; ++i) for (int j = 0; j < N_g; ++j) cost[i][j] = max_val - device_reach_prob[i][j];
    vector<int> assign = hungarian_solve_min_cost(cost); // assign[garbage] = device
    vector<int> new_d_out(N_g, -1);
    vector<char> device_taken(N_g, false);
    double total = 0.0;
    for (int g = 0; g < N_g; ++g) {
        int dev = assign[g];
        if (dev >= 0 && dev < N_g && !device_taken[dev]) {
            new_d_out[dev] = g;
            device_taken[dev] = true;
            total += device_reach_prob[g][dev];
        }
    }
    int gi = 0;
    for (int dev = 0; dev < N_g; ++dev) if (new_d_out[dev] == -1) {
        while (gi < N_g) {
            bool used = false;
            for (int d = 0; d < N_g; ++d) if (new_d_out[d] == gi) { used = true; break; }
            if (!used) break;
            ++gi;
        }
        if (gi < N_g) new_d_out[dev] = gi++;
        else new_d_out[dev] = 0;
    }
    return AssignmentResult{total, move(new_d_out)};
}

void optimize_sorter_orientations(int entrance_target, chrono::steady_clock::time_point deadline) {
    using clock_t = chrono::steady_clock;
    double base_score = compute_best_assignment(entrance_target).score;
    bool improved = true;
    while (improved) {
        improved = false;
        for (int i = 0; i < M_g; ++i) {
            if (clock_t::now() >= deadline) return;
            if (s_out[i].k == -1) continue;
            int v1 = s_out[i].v1, v2 = s_out[i].v2;
            if (v1 == -1 || v2 == -1 || v1 == v2) continue;
            swap(s_out[i].v1, s_out[i].v2);
            double sc = compute_best_assignment(entrance_target).score;
            if (sc > base_score) {
                base_score = sc;
                improved = true;
            } else {
                swap(s_out[i].v1, s_out[i].v2); // revert
            }
        }
    }
}

// Propagate probabilities from a node to devices for a specific garbage type
void dfs_propagate_to_devices(int garbage_type,
                              int node_id,
                              double prob,
                              vector<vector<double>>& device_reach_prob) {
    if (prob <= 0.0) return;
    if (node_id < N_g) {
        device_reach_prob[garbage_type][node_id] += prob;
        return;
    }
    int sorter_idx = node_id - N_g;
    if (sorter_idx < 0 || sorter_idx >= M_g) return;
    if (s_out[sorter_idx].k == -1) return; // no sorter installed (shouldn't be reached)
    int k = s_out[sorter_idx].k;
    int v1 = s_out[sorter_idx].v1;
    int v2 = s_out[sorter_idx].v2;
    double p1 = p_g[k][garbage_type];
    double p2 = 1.0 - p1;
    if (v1 != -1) dfs_propagate_to_devices(garbage_type, v1, prob * p1, device_reach_prob);
    if (v2 != -1) dfs_propagate_to_devices(garbage_type, v2, prob * p2, device_reach_prob);
}

// Hungarian algorithm (minimization). To maximize, pass cost = max_val - value
vector<int> hungarian_solve_min_cost(const vector<vector<double>>& cost) {
    int n = (int)cost.size();
    int m = (int)cost[0].size();
    int dim = max(n, m);
    vector<vector<double>> a(dim + 1, vector<double>(dim + 1, 0.0));
    for (int i = 1; i <= dim; ++i) {
        for (int j = 1; j <= dim; ++j) {
            if (i <= n && j <= m) a[i][j] = cost[i - 1][j - 1];
            else a[i][j] = 0.0;
        }
    }
    const double INF = 1e100;
    vector<double> u(dim + 1, 0.0), v(dim + 1, 0.0);
    vector<int> p(dim + 1, 0), way(dim + 1, 0);
    for (int i = 1; i <= dim; ++i) {
        p[0] = i;
        int j0 = 0;
        vector<double> minv(dim + 1, INF);
        vector<char> used(dim + 1, false);
        do {
            used[j0] = true;
            int i0 = p[j0], j1 = 0;
            double delta = INF;
            for (int j = 1; j <= dim; ++j) if (!used[j]) {
                double cur = a[i0][j] - u[i0] - v[j];
                if (cur < minv[j]) {
                    minv[j] = cur;
                    way[j] = j0;
                }
                if (minv[j] < delta) {
                    delta = minv[j];
                    j1 = j;
                }
            }
            for (int j = 0; j <= dim; ++j) {
                if (used[j]) { u[p[j]] += delta; v[j] -= delta; }
                else { minv[j] -= delta; }
            }
            j0 = j1;
        } while (p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }
    vector<int> assignment(n, -1);
    for (int j = 1; j <= dim; ++j) if (p[j] && p[j] <= n && j <= m) {
        assignment[p[j] - 1] = j - 1;
    }
    return assignment; // assignment[row] = column
}

BestSplit find_best_sorter(const vector<int>& garbage_indices) {
    BestSplit best;
    double best_score = -1.0;
    static const double T_LIST[] = {0.3, 0.4, 0.5, 0.6, 0.7};
    for (int i = 0; i < K_g; ++i) {
        for (double t : T_LIST) {
            int cnt_low = 0;
            double separation_score = 0.0;
            for (int j : garbage_indices) {
                double pij = p_g[i][j];
                separation_score += fabs(pij - t);
                if (pij < t) cnt_low++;
            }
            if (cnt_low == 0 || cnt_low == (int)garbage_indices.size()) continue;
            int cnt_high = (int)garbage_indices.size() - cnt_low;
            double balance = 1.0 - fabs(cnt_low - cnt_high) / (double)garbage_indices.size();
            double score = separation_score * balance;
            if (score > best_score) {
                best_score = score;
                best.k = i;
                best.t = t;
            }
        }
    }
    return best;
};

struct SplitCandidate { int k; double t; double score; };

vector<SplitCandidate> find_top_splits(const vector<int>& garbage_indices, int top_k) {
    vector<SplitCandidate> all;
    static const double T_LIST[] = {0.3, 0.4, 0.5, 0.6, 0.7};
    for (int i = 0; i < K_g; ++i) {
        for (double t : T_LIST) {
            int cnt_low = 0;
            double separation_score = 0.0;
            for (int j : garbage_indices) {
                double pij = p_g[i][j];
                separation_score += fabs(pij - t);
                if (pij < t) cnt_low++;
            }
            if (cnt_low == 0 || cnt_low == (int)garbage_indices.size()) continue;
            int cnt_high = (int)garbage_indices.size() - cnt_low;
            double balance = 1.0 - fabs(cnt_low - cnt_high) / (double)garbage_indices.size();
            double score = separation_score * balance;
            all.push_back({i, t, score});
        }
    }
    sort(all.begin(), all.end(), [](const SplitCandidate& a, const SplitCandidate& b){ return a.score > b.score; });
    if ((int)all.size() > top_k) all.resize(top_k);
    return all;
}

long long dist_sq_points(const Point& a, const Point& b) {
    long long dx = (long long)a.x - b.x;
    long long dy = (long long)a.y - b.y;
    return dx*dx + dy*dy;
}

vector<int> top_k_sorter_positions(const Point& from, int k) {
    vector<pair<long long,int>> items;
    items.reserve(M_g);
    for (int i = 0; i < M_g; ++i) {
        items.push_back({dist_sq_points(from, s_pos_g[i]), i});
    }
    nth_element(items.begin(), items.begin() + min(k, (int)items.size()) - 1, items.end());
    sort(items.begin(), items.begin() + min(k, (int)items.size()));
    vector<int> res;
    for (int i = 0; i < (int)items.size() && (int)res.size() < k; ++i) res.push_back(items[i].second);
    return res;
}

vector<int> top_k_device_positions(const Point& from, int k) {
    vector<pair<long long,int>> items;
    items.reserve(N_g);
    for (int i = 0; i < N_g; ++i) {
        items.push_back({dist_sq_points(from, d_pos_g[i]), i});
    }
    nth_element(items.begin(), items.begin() + min(k, (int)items.size()) - 1, items.end());
    sort(items.begin(), items.begin() + min(k, (int)items.size()));
    vector<int> res;
    for (int i = 0; i < (int)items.size() && (int)res.size() < k; ++i) res.push_back(items[i].second);
    return res;
}

void split_group_by_kt(const vector<int>& garbage_group, int k, double t, vector<int>& group_low, vector<int>& group_high) {
    group_low.clear();
    group_high.clear();
    for (int g : garbage_group) {
        if (p_g[k][g] < t) group_low.push_back(g);
        else group_high.push_back(g);
    }
}

struct FullState {
    vector<bool> s_used, d_used, g_assigned;
    vector<pair<Point,Point>> belts;
    vector<SorterOutput> souts;
    vector<int> dout;
};

FullState snapshot_full_state() {
    return FullState{ s_pos_used_g, d_pos_used_g, garbage_assigned_g, belts_g, s_out, d_out };
}

void restore_full_state(const FullState& st) {
    s_pos_used_g = st.s_used;
    d_pos_used_g = st.d_used;
    garbage_assigned_g = st.g_assigned;
    belts_g = st.belts;
    s_out = st.souts;
    d_out = st.dout;
}

struct Candidate {
    vector<pair<Point,Point>> belts;
    vector<SorterOutput> souts;
    int entrance_target = -1;
    vector<int> final_dout;
    double score = -1.0;
};

bool try_forced_sorter_at_root(const Point& entrance_pos,
                               const vector<int>& all_garbage,
                               int m_idx,
                               int k,
                               double t,
                               int& out_entrance_target) {
    if (m_idx < 0 || m_idx >= M_g) return false;
    if (s_pos_used_g[m_idx]) return false;
    pair<Point, Point> cand_belt = {entrance_pos, s_pos_g[m_idx]};
    if (has_intersection(cand_belt, belts_g)) return false;
    s_pos_used_g[m_idx] = true;
    belts_g.push_back(cand_belt);
    vector<int> group_low, group_high;
    split_group_by_kt(all_garbage, k, t, group_low, group_high);
    if (group_low.empty() || group_high.empty()) {
        belts_g.pop_back();
        s_pos_used_g[m_idx] = false;
        return false;
    }
    int v1 = build_tree(s_pos_g[m_idx], group_high);
    int v2 = build_tree(s_pos_g[m_idx], group_low);
    if (v1 == -1 && v2 == -1) {
        belts_g.pop_back();
        s_pos_used_g[m_idx] = false;
        return false;
    }
    if (v1 == -1) v1 = v2;
    if (v2 == -1) v2 = v1;
    s_out[m_idx] = {k, v1, v2};
    out_entrance_target = N_g + m_idx;
    return true;
}

bool try_forced_device_at_root(const Point& entrance_pos,
                               int d_idx,
                               int& out_entrance_target) {
    if (d_idx < 0 || d_idx >= N_g) return false;
    if (d_pos_used_g[d_idx]) return false;
    pair<Point, Point> cand_belt = {entrance_pos, d_pos_g[d_idx]};
    if (has_intersection(cand_belt, belts_g)) return false;
    d_pos_used_g[d_idx] = true;
    belts_g.push_back(cand_belt);
    out_entrance_target = d_idx;
    return true;
}

// Finds the most "representative" garbage type from a group.
int find_representative_garbage(const vector<int>& garbage_group) {
    if (garbage_group.empty()) return -1;
    int rep_garbage = -1;
    double max_p_dist = -1.0;
    for (int g : garbage_group) {
        double min_dist_from_half = 1.0;
        for (int i = 0; i < K_g; ++i) {
            min_dist_from_half = min(min_dist_from_half, abs(p_g[i][g] - 0.5));
        }
        if (min_dist_from_half > max_p_dist) {
            max_p_dist = min_dist_from_half;
            rep_garbage = g;
        }
    }
    return rep_garbage == -1 ? garbage_group[0] : rep_garbage;
}

// Recursively builds the sorter tree. Returns the ID of the connected node.
int build_tree(Point parent_pos, const vector<int>& garbage_group); // Forward declaration

int place_leaf_node(Point parent_pos, const vector<int>& garbage_group) {
    if (garbage_group.empty()) return -1;
    int garbage_type = find_representative_garbage(garbage_group);

    if (garbage_assigned_g[garbage_type]) {
        return -1;
    }

    long long best_dist_sq = -1;
    int best_d_idx = -1;
    for (int i = 0; i < N_g; ++i) {
        if (d_pos_used_g[i]) continue;
        pair<Point, Point> cand_belt = {parent_pos, d_pos_g[i]};
        if (!has_intersection(cand_belt, belts_g)) {
            long long dist_sq = (long long)(d_pos_g[i].x - parent_pos.x) * (d_pos_g[i].x - parent_pos.x) + (long long)(d_pos_g[i].y - parent_pos.y) * (d_pos_g[i].y - parent_pos.y);
            if (best_d_idx == -1 || dist_sq < best_dist_sq) {
                best_dist_sq = dist_sq;
                best_d_idx = i;
            }
        }
    }

    if (best_d_idx != -1) {
        d_out[best_d_idx] = garbage_type;
        d_pos_used_g[best_d_idx] = true;
        garbage_assigned_g[garbage_type] = true;
        belts_g.push_back({parent_pos, d_pos_g[best_d_idx]});
        return best_d_idx;
    }
    return -1;
}

int build_tree(Point parent_pos, const vector<int>& garbage_group) {
    if (garbage_group.size() <= 1) {
        return place_leaf_node(parent_pos, garbage_group);
    }

    BestSplit bs = find_best_sorter(garbage_group);
    int k = bs.k;
    double t = bs.t;
    if (k == -1) {
        return place_leaf_node(parent_pos, garbage_group);
    }

    long long best_dist_sq = -1;
    int m = -1;
    for (int i = 0; i < M_g; ++i) {
        if (s_pos_used_g[i]) continue;
        pair<Point, Point> cand_belt = {parent_pos, s_pos_g[i]};
        if (!has_intersection(cand_belt, belts_g)) {
            long long dist_sq = (long long)(s_pos_g[i].x - parent_pos.x) * (s_pos_g[i].x - parent_pos.x) + (long long)(s_pos_g[i].y - parent_pos.y) * (s_pos_g[i].y - parent_pos.y);
            if (m == -1 || dist_sq < best_dist_sq) {
                best_dist_sq = dist_sq;
                m = i;
            }
        }
    }

    if (m == -1) {
        return place_leaf_node(parent_pos, garbage_group);
    }

    s_pos_used_g[m] = true;
    belts_g.push_back({parent_pos, s_pos_g[m]});

    vector<int> group1, group2; // group1: p<t, group2: p>=t
    for (int g : garbage_group) {
        if (p_g[k][g] < t) group1.push_back(g);
        else group2.push_back(g);
    }

    if (group1.empty() || group2.empty()) {
        belts_g.pop_back();
        s_pos_used_g[m] = false;
        return place_leaf_node(parent_pos, garbage_group);
    }

    int v1_target = build_tree(s_pos_g[m], group2);
    int v2_target = build_tree(s_pos_g[m], group1);

    if (v1_target == -1 && v2_target == -1) {
        belts_g.pop_back();
        s_pos_used_g[m] = false;
        return place_leaf_node(parent_pos, garbage_group);
    }

    if (v1_target == -1) v1_target = v2_target;
    if (v2_target == -1) v2_target = v1_target;

    s_out[m] = {k, v1_target, v2_target};

    return N_g + m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N_g >> M_g >> K_g;

    d_pos_g.resize(N_g);
    for (int i = 0; i < N_g; ++i) cin >> d_pos_g[i].x >> d_pos_g[i].y;

    s_pos_g.resize(M_g);
    for (int i = 0; i < M_g; ++i) cin >> s_pos_g[i].x >> s_pos_g[i].y;

    p_g.resize(K_g, vector<double>(N_g));
    for (int i = 0; i < K_g; ++i) {
        for (int j = 0; j < N_g; ++j) {
            cin >> p_g[i][j];
        }
    }

    s_pos_used_g.assign(M_g, false);
    d_pos_used_g.assign(N_g, false);
    d_out.assign(N_g, -1);
    garbage_assigned_g.assign(N_g, false);
    s_out.assign(M_g, SorterOutput());

    Point entrance_pos = {0, 5000};
    vector<int> all_garbage(N_g);
    iota(all_garbage.begin(), all_garbage.end(), 0);

    int entrance_target = -1;
    // Time control
    using clock_t = chrono::steady_clock;
    auto t_start = clock_t::now();
    auto deadline = t_start + chrono::milliseconds(1800);
    // Beam search at root (time-controlled)
    int BEAM_SPLITS = min(20, K_g * 5); // consider up to 20 split choices
    int BEAM_POS = min(20, M_g);        // consider up to 20 nearest sorter positions
    vector<Candidate> beam;
    {
        // Baseline: original recursive build
        FullState snap = snapshot_full_state();
        int ent = build_tree(entrance_pos, all_garbage);
        optimize_sorter_orientations(ent, deadline);
        AssignmentResult ar = compute_best_assignment(ent);
        beam.push_back(Candidate{belts_g, s_out, ent, ar.device_to_type, ar.score});
        restore_full_state(snap);
    }
    // Try forcing a sorter at the root among top split/position candidates
    vector<SplitCandidate> splits = find_top_splits(all_garbage, BEAM_SPLITS);
    vector<int> pos_cands = top_k_sorter_positions(entrance_pos, BEAM_POS);
    for (const auto& sp : splits) {
        if (clock_t::now() >= deadline) break;
        for (int m_idx : pos_cands) {
            if (clock_t::now() >= deadline) break;
            FullState snap = snapshot_full_state();
            int ent = -1;
            if (try_forced_sorter_at_root(entrance_pos, all_garbage, m_idx, sp.k, sp.t, ent)) {
                optimize_sorter_orientations(ent, deadline);
                AssignmentResult ar = compute_best_assignment(ent);
                beam.push_back(Candidate{belts_g, s_out, ent, ar.device_to_type, ar.score});
            }
            restore_full_state(snap);
        }
    }
    // Also try directly connecting to a few nearest devices
    vector<int> dev_pos = top_k_device_positions(entrance_pos, min(3, N_g));
    for (int d_idx : dev_pos) {
        if (clock_t::now() >= deadline) break;
        FullState snap = snapshot_full_state();
        int ent = -1;
        if (try_forced_device_at_root(entrance_pos, d_idx, ent)) {
            AssignmentResult ar = compute_best_assignment(ent);
            beam.push_back(Candidate{belts_g, s_out, ent, ar.device_to_type, ar.score});
        }
        restore_full_state(snap);
    }
    // Select best candidate
    if (!beam.empty()) {
        auto best_it = max_element(beam.begin(), beam.end(), [](const Candidate& a, const Candidate& b){ return a.score < b.score; });
        belts_g = best_it->belts;
        s_out = best_it->souts;
        entrance_target = best_it->entrance_target;
        d_out = best_it->final_dout;
    } else {
        entrance_target = build_tree(entrance_pos, all_garbage);
    }

    if (entrance_target == -1) {
        entrance_target = 0;
        if (!garbage_assigned_g[0]) {
             d_out[0] = 0;
             garbage_assigned_g[0] = true;
        }
    }

    // Beam result already has assignment; if not assigned, run final assignment
    if (d_out.size() != (size_t)N_g) d_out.assign(N_g, -1);
    bool need_final_assign = false;
    for (int i = 0; i < N_g; ++i) if (d_out[i] == -1) { need_final_assign = true; break; }
    if (need_final_assign) {
        optimize_sorter_orientations(entrance_target, deadline);
        AssignmentResult final_assign = compute_best_assignment(entrance_target);
        d_out.swap(final_assign.device_to_type);
    }

    // Output
    for (int i = 0; i < N_g; ++i) {
        cout << d_out[i] << (i == N_g - 1 ? "" : " ");
    }
    cout << endl;

    cout << entrance_target << endl;

    for (int i = 0; i < M_g; ++i) {
        if (s_out[i].k != -1) {
             cout << s_out[i].k << " " << s_out[i].v1 << " " << s_out[i].v2 << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
