#include <bits/stdc++.h>
using namespace std;

struct Color {
    double c, m, y;
};

struct Leftover {
    Color color;
    int r, c;
    int well_size;
};

Color mix_50_50(const Color& a, const Color& b) {
    return { (a.c + b.c) / 2.0, (a.m + b.m) / 2.0, (a.y + b.y) / 2.0 };
}

double calculate_distance(const Color& a, const Color& b) {
    return pow(a.c - b.c, 2) + pow(a.m - b.m, 2) + pow(a.y - b.y, 2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K, H, T, D; cin >> N >> K >> H >> T >> D;
    // N = 20, 4<=K<=20, H=1000, 4000<=T<=64000, 10<=D<=10000

    vector<Color> own_colors(K);
    for (int i = 0; i < K; i++) {
        cin >> own_colors[i].c >> own_colors[i].m >> own_colors[i].y;
    }
    vector<Color> target_colors(H);
    for (int i = 0; i < H; i++) {
        cin >> target_colors[i].c >> target_colors[i].m >> target_colors[i].y;
    }

    // --------------------------------------------------------

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            cout << 1 << (j == N - 2 ? "" : " ");
        }
        cout << endl;
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N; j++) {
            cout << 1 << (j == N - 1 ? "" : " ");
        }
        cout << endl;
    }

    // --------------------------------------------------------

    vector<Leftover> leftovers;
    vector<bool> is_cell_used(N * N, false);

    for (int h = 0; h < H; ++h) {

        // 新規作成する場合のベストを探す
        int best_j = -1, best_l = -1;
        double min_dist_sq_A = numeric_limits<double>::max();
        for (int j = 0; j < K; ++j) {
            for (int l = j + 1; l < K; ++l) {
                Color mixed = mix_50_50(own_colors[j], own_colors[l]);
                double dist_sq = calculate_distance(target_colors[h], mixed);
                if (dist_sq < min_dist_sq_A) {
                    min_dist_sq_A = dist_sq;
                    best_j = j;
                    best_l = l;
                }
            }
        }

        // 再利用する場合のベストを探す
        int best_leftover_idx = -1;
        double min_dist_sq_B = numeric_limits<double>::max();
        for (int i = 0; i < leftovers.size(); ++i) {
            double dist_sq = calculate_distance(target_colors[h], leftovers[i].color);
            if (dist_sq < min_dist_sq_B) {
                min_dist_sq_B = dist_sq;
                best_leftover_idx = i;
            }
        }

        int r1 = -1, c1 = -1, r2 = -1, c2 = -1;
        for(int i=0; i<N*N - 1; ++i) {
            if (!is_cell_used[i] && !is_cell_used[i+1]) {
                if ( (i % N) != (N - 1) ) {
                    r1 = i / N; c1 = i % N;
                    r2 = (i+1) / N; c2 = (i+1) % N;
                    break;
                }
            }
        }

        if (r1 != -1 && min_dist_sq_A < min_dist_sq_B) {
            is_cell_used[r1 * N + c1] = true;
            is_cell_used[r2 * N + c2] = true;

            cout << "1 " << r1 << " " << c1 << " " << best_j << "\n";
            cout << "1 " << r2 << " " << c2 << " " << best_l << "\n";
            cout << "4 " << r1 << " " << c1 << " " << r2 << " " << c2 << "\n";
            cout << "2 " << r1 << " " << c1 << "\n";

            leftovers.push_back({mix_50_50(own_colors[best_j], own_colors[best_l]), r1, c1, 2});

        } else {
            if (leftovers.empty()) {
                continue; // ありえないはず
            }
            Leftover used_leftover = leftovers[best_leftover_idx];
            int r = used_leftover.r, c = used_leftover.c;

            cout << "2 " << r << " " << c << "\n";

            int r2 = r, c2 = c + 1;
            cout << "4 " << r << " " << c << " " << r2 << " " << c2 << "\n";

            is_cell_used[r*N + c] = false;
            is_cell_used[r*N + c2] = false;
            leftovers.erase(leftovers.begin() + best_leftover_idx);
        }
    }

    return 0;
}
