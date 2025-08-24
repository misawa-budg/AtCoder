#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    vector<string> A(H);
    for (int i = 0; i < H; ++i) cin >> A[i];

    pair<int,int> S{-1,-1}, G{-1,-1};
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] == 'S') S = {i,j};
            if (A[i][j] == 'G') G = {i,j};
        }
    }

    auto ok = [&](int x, int y, int p) -> bool {
        char c = A[x][y];
        if (c == '#') return false;
        if (c == 'o') return (p == 0);
        if (c == 'x') return (p == 1);
        return true;
    };

    vector<vector<vector<int>>> dist(H, vector<vector<int>>(W, vector<int>(2, INT_MAX)));
    queue<tuple<int, int, int>> q;
    dist[S.first][S.second][0] = 0;
    q.emplace(S.first, S.second, 0);
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int ans = -1;
    while (!q.empty()) {
        auto [x, y, p] = q.front(); q.pop();
        int d = dist[x][y][p];
        if (x == G.first && y == G.second) {
            ans = d;
            break;
        }
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (!ok(nx, ny, p)) continue;

            int np = p;
            if (A[nx][ny] == '?') np ^= 1;
            if (dist[nx][ny][np] > d + 1) {
                dist[nx][ny][np] = d + 1;
                q.emplace(nx, ny, np);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
