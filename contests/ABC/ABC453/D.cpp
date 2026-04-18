#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    vector<vector<char>> S(H, vector<char>(W));
    int sr=-1, sc=-1, gr=-1, gc=-1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> S[i][j];
            if (S[i][j] == 'S') {
                sr = i; sc = j;
            } else if (S[i][j] == 'G') {
                gr = i; gc = j;
            }
        }
    }

    vector<vector<vector<bool>>> visited(H, vector<vector<bool>>(W, vector<bool>(4, false)));
    vector<vector<vector<int>>> prev_dir(H, vector<vector<int>>(W, vector<int>(4)));

    int dr[] = {0, 0, -1, 1}; int dc[] = {-1, 1, 0, 0};
    char dirs[] = {'L', 'R', 'U', 'D'};

    queue<tuple<int, int, int>> q;
    
    for (int i = 0; i < 4; i++) {
        int nr = sr + dr[i];
        int nc = sc + dc[i];
        if (nr < 0 || H <= nr || nc < 0 || W <= nc) continue;
        if (S[nr][nc] == '#') continue;
        visited[nr][nc][i] = true;
        prev_dir[nr][nc][i] = -1;
        q.emplace(nr, nc, i);
    }

    int goal_dir = -1;

    while (!q.empty()) {
        auto [cr, cc, dir] = q.front(); q.pop();
        if (cr == gr && cc == gc) { goal_dir = dir; break;}

        for (int i = 0; i < 4; i++) {
            if (S[cr][cc] == 'o' && dir != i) continue;
            if (S[cr][cc] == 'x' && dir == i) continue;
            int nr = cr + dr[i]; int nc = cc + dc[i];
            if (nr < 0 || H <= nr || nc < 0 || W <= nc) continue;
            if (S[nr][nc] == '#') continue;
            if (visited[nr][nc][i]) continue;

            visited[nr][nc][i] = true;
            prev_dir[nr][nc][i] = dir;
            q.emplace(nr, nc, i);
        }
    }

    if (goal_dir == -1) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        string ans;
        int cr = gr, cc = gc, d = goal_dir;
        
        while (d != -1) {
            ans += dirs[d];
            int pr = cr - dr[d];
            int pc = cc - dc[d];
            d = prev_dir[cr][cc][d];
            cr = pr; cc = pc;
        }

        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }


    return 0;
}
