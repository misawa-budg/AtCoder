#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    vector<vector<long long>> A(H, vector<long long>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> used(H, vector<bool>(W, false));
    long long ans = 0;
    auto dfs = [&](auto&& self, int h, int w, vector<vector<bool>>& used) -> void {
        if (h == H) {
            long long score = 0;
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    if (!used[i][j]) score ^= A[i][j];
                }
            }
            ans = max(ans, score);
            return;
        }

        int nextH = (w == W - 1) ? h + 1 : h;
        int nextW = (w == W - 1) ? 0 : w + 1;

        if (used[h][w]) {
            self(self, nextH, nextW, used);
            return;
        }

        // 何もしない
        self(self, nextH, nextW, used);

        // 横置き
        if (w + 1 < W && !used[h][w + 1]) {
            used[h][w] = true;
            used[h][w + 1] = true;
            self(self, nextH, nextW, used);
            used[h][w] = false;
            used[h][w + 1] = false;
        }

        // 縦置き
        if (h + 1 < H && !used[h + 1][w]) {
            used[h][w] = true;
            used[h + 1][w] = true;
            self(self, nextH, nextW, used);
            used[h][w] = false;
            used[h + 1][w] = false;
        }
    };

    dfs(dfs, 0, 0, used);

    cout << ans << '\n';

    return 0;
}
