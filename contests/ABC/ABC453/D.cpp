#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    vector<string> grid(H); for (int i = 0; i < H; i++) cin >> grid[i];

    int dr[] = {-1, 1, 0, 0}; int dc[] = {0, 0, -1, 1};

    int sr, sc, gr, gc;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == 'S') { sr = i; sc = j; }
            if (grid[i][j] == 'G') { gr = i; gc = j; }
        }
    }

    vector dist(H, vector(W, vector<int>(4, INT_MIN)));
    vector pr(H, vector(W, vector<tuple<int, int, int>>(4, {-1, -1, -1})));
    
    queue<tuple<int, int, int>> q;

    for (int i = 0; i < 4; i++) {
        dist[sr][sc][i] = 0;
        q.emplace(sr, sc, i);
    }

    int final_dir = -1;
    while (!q.empty()) {
        auto [r, c, d] = q.front(); q.pop();

        if (r == gr && c == gc) {
            final_dir = d;
            break;
        }

        char cur = grid[r][c];
        for (int i = 0; i < 4; i++) {
            if (cur == 'o' && d != i) continue;
            if (cur == 'x' && d == i) continue;

            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || H <= nr || nc < 0 || W <= nc) continue;
            if (grid[nr][nc] == '#' || dist[nr][nc][i] != INT_MIN) continue;

            dist[nr][nc][i] = dist[r][c][d] + 1;
            pr[nr][nc][i] = {r, c, d};
            q.emplace(nr, nc, i);
        }
    }

    char dir[] = {'U', 'D', 'L', 'R'};

    if (final_dir == -1) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        string ans = "";
        int curr = gr, curc = gc, curd = final_dir;

        while (curr != sr || curc != sc) {
            ans += dir[curd];
            auto [prevr, prevc, prevd] = pr[curr][curc][curd];
            curr = prevr; curc = prevc; curd = prevd;
        }

        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }

    return 0;
}
