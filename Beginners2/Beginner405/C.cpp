#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    vector<string> grid(H);
    for (int i = 0; i < H; i++) cin >> grid[i];

    queue<pair<int, int>> q;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == 'E') q.emplace(i, j);
        }
    }

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    auto ok = [&](int i, int j) {
        return i >= 0 && i < H && j >= 0 && j < W && grid[i][j] == '.';
    };
    string dir = "^<v>";
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ok(ni, nj)) {
                grid[ni][nj] = dir[k];
                q.emplace(ni, nj);
            }
        }
    }

    for (int i = 0; i < H; i++) {
        cout << grid[i] << '\n';
    }

    return 0;
}
