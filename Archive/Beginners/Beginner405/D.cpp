#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    vector<string> S(H); for (int i = 0; i < H; i++) cin >> S[i];

    vector<vector<int>> steps(H, vector<int>(W, INT_MAX));
    queue<pair<int, int>> q;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == 'E') {
                steps[i][j] = 0;
                q.emplace(i, j);
            }
        }
    }

    vector<pair<int, int>> directions = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };

    vector<string> ans = S;
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (auto [di, dj] : directions) {
            int ni = i + di; int nj = j + dj;
            if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
            if (S[ni][nj] == '#') continue;
            if (steps[ni][nj] > steps[i][j] + 1) {
                steps[ni][nj] = steps[i][j] + 1;
                q.push({ni, nj});

                if (di == 0 && dj == 1) ans[ni][nj] = '<';
                else if (di == 1 && dj == 0) ans[ni][nj] = '^';
                else if (di == 0 && dj == -1) ans[ni][nj] = '>';
                else if (di == -1 && dj == 0) ans[ni][nj] = 'v';
            }
        }
    }


    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }

    return 0;
}
