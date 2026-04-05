#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    vector<string> S(H);
    vector<vector<pair<int, int>>> ports(26);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
        for (int j = 0; j < W; j++) {
            if ('a' <= S[i][j] && S[i][j] <= 'z') {
                ports[S[i][j] - 'a'].emplace_back(i, j);
            }
        }
    }


    auto inside = [&](int r, int c) {
        return 0 <= r && r < H && 0 <= c && c < W;
    };

    vector<vector<int>> costs(H, vector<int>(W, -1));
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    vector<bool> used(26, false);

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    queue<pair<int, int>> q;
    q.emplace(0, 0);
    costs[0][0] = 0;
    visited[0][0] = true;
    while (!q.empty()) {
        auto [curr, curc] = q.front(); q.pop();
        if (curr == H - 1 && curc == W - 1) break;

        for (int dir = 0; dir < 4; dir++) {
            int nextr = curr + dr[dir];
            int nextc = curc + dc[dir];
            if (!inside(nextr, nextc)) continue;
            if (visited[nextr][nextc]) continue;
            if (S[nextr][nextc] == '#') continue;

            visited[nextr][nextc] = true;
            costs[nextr][nextc] = costs[curr][curc] + 1;
            q.emplace(nextr, nextc);
        }

        if ('a' <= S[curr][curc] && S[curr][curc] <= 'z') {
            if (used[S[curr][curc] - 'a']) continue;
            for (const auto& [nextr, nextc] : ports[S[curr][curc] - 'a']) {
                if (nextr == curr && nextc == curc) continue;
                if (visited[nextr][nextc]) continue;

                visited[nextr][nextc] = true;
                costs[nextr][nextc] = costs[curr][curc] + 1;
                q.emplace(nextr, nextc);
            }
            used[S[curr][curc] - 'a'] = true;
        }
    }

    cout << costs[H - 1][W - 1] << '\n';

    return 0;
}
