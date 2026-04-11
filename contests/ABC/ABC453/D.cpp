#include <bits/stdc++.h>
using namespace std;

struct State {
    int r, c, dir;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, W; cin >> H >> W;
    vector<string> S(H);
    int sr = -1, sc = -1, gr = -1, gc = -1;
    for (int i = 0; i < H; i++) {
        cin >> S[i];
        for (int j = 0; j < W; j++) {
            if (S[i][j] == 'S') {
                sr = i; sc = j;
            } else if (S[i][j] == 'G') {
                gr = i; gc = j;
            }
        }
    }

    vector<vector<vector<bool>>> visited(H, vector<vector<bool>>(W, vector<bool>(4, false)));
    vector<vector<vector<State>>> prev_s(H, vector<vector<State>>(W, vector<State>(4, {-1, -1, -1})));
    queue<State> q;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    char dirs[] = {'U', 'D', 'L', 'R'};

    for (int i = 0; i < 4; i++) {
        int nr = sr + dr[i];
        int nc = sc + dc[i];
        if (0 <= nr && nr < H && 0 <= nc && nc < W && S[nr][nc] != '#') {
            visited[nr][nc][i] = true;
            q.push({nr, nc, i});
        }
    }

    State goal_state = {-1, -1, -1};

    while (!q.empty()) {
        auto [r, c, dir] = q.front();
        q.pop();

        if (r == gr && c == gc) {
            goal_state = {r, c, dir};
            break;
        }

        char current_cell = S[r][c];
        
        for (int ndir = 0; ndir < 4; ndir++) {
            if (current_cell == 'o' && ndir != dir) continue;
            if (current_cell == 'x' && ndir == dir) continue;

            int nr = r + dr[ndir];
            int nc = c + dc[ndir];

            if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
            if (S[nr][nc] == '#') continue;

            if (!visited[nr][nc][ndir]) {
                visited[nr][nc][ndir] = true;
                prev_s[nr][nc][ndir] = {r, c, dir};
                q.push({nr, nc, ndir});
            }
        }
    }

    if (goal_state.r == -1) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        string ans = "";
        State curr = goal_state;
        
        while (curr.r != -1) {
            ans += dirs[curr.dir];
            curr = prev_s[curr.r][curr.c][curr.dir];
        }
        
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }

    return 0;
}
