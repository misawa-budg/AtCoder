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

int find_best_sorter(const vector<int>& garbage_indices) {
    int best_k = -1;
    double max_final_score = -1.0;

    for (int i = 0; i < K_g; ++i) {
        double separation_score = 0;
        int group1_size = 0;
        for (int j : garbage_indices) {
            separation_score += abs(p_g[i][j] - 0.5);
            if (p_g[i][j] < 0.5) group1_size++;
        }

        if (group1_size == 0 || group1_size == garbage_indices.size()) continue;

        int group2_size = garbage_indices.size() - group1_size;
        double balance_score = 1.0 - abs(group1_size - group2_size) / (double)garbage_indices.size();

        double final_score = separation_score * balance_score;

        if (final_score > max_final_score) {
            max_final_score = final_score;
            best_k = i;
        }
    }
    return best_k;
};

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

    int k = find_best_sorter(garbage_group);
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

    vector<int> group1, group2; // group1: p<0.5, group2: p>=0.5
    for (int g : garbage_group) {
        if (p_g[k][g] < 0.5) group1.push_back(g);
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

    int entrance_target = build_tree(entrance_pos, all_garbage);

    if (entrance_target == -1) {
        entrance_target = 0;
        if (!garbage_assigned_g[0]) {
             d_out[0] = 0;
             garbage_assigned_g[0] = true;
        }
    }

    // Assign any garbage that was left over
    int current_d_pos = 0;
    for (int i = 0; i < N_g; ++i) {
        if (!garbage_assigned_g[i]) {
            while(current_d_pos < N_g && d_pos_used_g[current_d_pos]) {
                current_d_pos++;
            }
            if (current_d_pos < N_g) {
                d_out[current_d_pos] = i;
                d_pos_used_g[current_d_pos] = true;
                garbage_assigned_g[i] = true;
            }
        }
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
