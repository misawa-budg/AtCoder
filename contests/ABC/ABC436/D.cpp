#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    vector<vector<pair<int, int>>> warps(26);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if ('a' <= S[i][j] && S[i][j] <= 'z') {
                warps[S[i][j] - 'a'].emplace_back(i, j);
            }
        }
    }

    vector<vector<int>> dist(H, vector<int>(W, -1));
    vector<bool> used(26, false);

    queue<pair<int, int>> q;
    dist[0][0] = 0;
    q.push({0, 0});

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == H - 1 && y == W - 1) {
            cout << dist[x][y] << '\n';
            return 0;
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (S[nx][ny] == '#') continue;
            if (dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }

        if ('a' <= S[x][y] && S[x][y] <= 'z') {
            int c = S[x][y] - 'a';
            if (!used[c]) {
                used[c] = true;
                for (auto [nx, ny] : warps[c]) {
                    if (dist[nx][ny] != -1) continue;
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    cout << -1 << '\n';

    return 0;
}
