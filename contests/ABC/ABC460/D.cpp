#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;

    // 白 -> 最短の黒マスとの距離 -> 振動
    // 黒 -> 白 -> 最短の白マスとの距離 -> 振動

    vector<string> grid(H);
    bool hasB = false, hasW = false;

    for (int i = 0; i < H; i++) {
        cin >> grid[i];
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == '#') hasB = true;
            if (grid[i][j] == '.') hasW = true;
        }
    }

    if (!hasB || !hasW) {
        for (int i = 0; i < H; i++) {
            cout << string(W, '.') << '\n';
        }
        return 0;
    }

    vector dB(H, vector<int>(W, -1));
    vector dW(H, vector<int>(W, -1));

    queue<pair<int, int>> qB, qW;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == '#') {
                dB[i][j] = 0;
                qB.emplace(i, j);
            } else {
                dW[i][j] = 0;
                qW.emplace(i, j);
            }
        }
    }

    auto bfs = [&](queue<pair<int, int>>& q, vector<vector<int>>& dist) {
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i == 0 && j == 0) continue;

                    int nr = r + i;
                    int nc = c + j;

                    if (0 <= nr && nr < H && 0 <= nc && nc < W) {
                        if (dist[nr][nc] == -1) {
                            dist[nr][nc] = dist[r][c] + 1;
                            q.emplace(nr, nc);
                        }
                    }
                }
            }
        }
    };

    bfs(qB, dB); bfs(qW, dW);

    for (int i = 0; i < H; i++) {
        string ans;
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == '.') {
                ans += (dB[i][j] % 2 == 0) ? '#' : '.';
            } else {
                ans += (dW[i][j] % 2 == 1) ? '#' : '.';
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
