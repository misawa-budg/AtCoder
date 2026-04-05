#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    set<pair<int, int>> s;

    int dx[] = {1, 1, 0, 0};
    int dy[] = {0, 1, 0, 1};

    int total = 0;
    for (int i = 0; i < M; i++) {
        int r, c; cin >> r >> c;
        bool unique = true;

        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dy[dir];
            int nc = c + dx[dir];
            if (s.contains(make_pair(nr, nc))) {
                unique = false;
                break;
            }
        }

        if (!unique) continue;

        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dy[dir];
            int nc = c + dx[dir];
            s.emplace(nr, nc);
        }

        total++;
    }

    cout << total << '\n';

    return 0;
}
