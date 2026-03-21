#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    int ans = 0;

    int dy[] = {-1, 1, 0, 0};
    int dx[] = {0, 0, -1, 1};

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (S[i][j] == '.' && !visited[i][j]) {
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                
                bool is_surrounded = true;

                while (!q.empty()) {
                    auto [y, x] = q.front();
                    q.pop();

                    if (y == 0 || y == H - 1 || x == 0 || x == W - 1) {
                        is_surrounded = false;
                    }

                    for (int dir = 0; dir < 4; ++dir) {
                        int ny = y + dy[dir];
                        int nx = x + dx[dir];

                        if (0 <= ny && ny < H && 0 <= nx && nx < W) {
                            if (S[ny][nx] == '.' && !visited[ny][nx]) {
                                visited[ny][nx] = true;
                                q.push({ny, nx});
                            }
                        }
                    }
                }
                if (is_surrounded) ans++;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
