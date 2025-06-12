#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<string> grid;
vector<bool> visited;
int ans = -1;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int cx, int cy, int sx, int sy, int step)
{
    for (int i = 0; i < 4; i++) {
        int nx = cx + dx[i], ny = cy + dy[i];
        if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;

        if (nx == sx && ny == sy) {
            if (step >= 3) ans = max(ans, step);
            continue;
        }

        if (visited[nx * W + ny] || grid[nx][ny] == '#') continue;
        visited[nx * W + ny] = true;
        dfs(nx, ny, sx, sy, step + 1);
        visited[nx * W + ny] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W;
    grid.resize(H);
    for (int i = 0; i < H; i++) cin >> grid[i];

    visited.resize(H * W, false);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == '#') continue;
            visited[i * W + j] = true;
            dfs(i, j, i, j, 1);
            visited[i * W + j] = false;
        }
    }

    cout << ans << endl;

    return 0;
}
