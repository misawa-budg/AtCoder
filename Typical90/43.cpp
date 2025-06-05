#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    pair<int, int> start, end;
    cin >> start.first >> start.second >> end.first >> end.second;
    start.first--; start.second--; end.first--; end.second--;
    vector<string> grid(H);
    for (int i = 0; i < H; i++) {
        cin >> grid[i];
    }
    vector dist(H, vector(W, array<int, 4>{INT_MAX, INT_MAX, INT_MAX, INT_MAX}));
    auto check = [&](int x, int y) {return x >= 0 && x < H && y >= 0 && y < W;};

    deque<tuple<int, int, int>> dq;
    for (int dir = 0; dir < 4; dir++) {
        dist[start.first][start.second][dir] = 0;
        dq.emplace_back(start.first, start.second, dir);
    }

    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};

    while (!dq.empty()) {
        auto [r, c, dir] = dq.front(); dq.pop_front();
        int cost = dist[r][c][dir];

        for (int ndir = 0; ndir < 4; ndir++) {
            int nr = r + dr[ndir], nc = c + dc[ndir];
            if (!check(nr, nc) || grid[nr][nc] == '#') continue;

            int add = (ndir == dir) ? 0 : 1;
            int ncost = cost + add;
            if (ncost < dist[nr][nc][ndir]) {
                dist[nr][nc][ndir] = ncost;
                if (add == 0) {
                    dq.emplace_front(nr, nc, ndir);
                } else {
                    dq.emplace_back(nr, nc, ndir);
                }
            }
        }
    }

    int ans = *min_element(dist[end.first][end.second].begin(), dist[end.first][end.second].end());
    cout << ans << endl;

    return 0;
}
