#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long H, W, K; cin >> H >> W >> K;
    vector<string> grid(H);
    for (int i = 0; i < H; i++) {
        cin >> grid[i];
    }

    vector<bool> row(H), col(W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == '#') {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    vector<vector<int>> dist(H, vector<int>(W, -1));
    queue<pair<int, int>> q;
    
    long long ans = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == '.' && !row[i] && !col[j]) {
                dist[i][j] = 0;
                q.push({i, j});
                ans++;
            }
        }
    }

    int di[] = {1, -1, 0, 0};
    int dj[] = {0, 0, 1, -1};

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        if (dist[i][j] == K) continue;

        for (int d = 0; d < 4; d++) {
            int ni = i + di[d];
            int nj = j + dj[d];

            if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
            if (grid[ni][nj] == '#') continue;
            if (dist[ni][nj] != -1) continue;

            dist[ni][nj] = dist[i][j] + 1;
            q.push({ni, nj});
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
