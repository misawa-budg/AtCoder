#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, N; cin >> H >> W >> N;
    vector<vector<int>> row(H), col(W);
    vector<int> rowCnt(H, 0), colCnt(W, 0);

    for (int k = 0; k < N; ++k) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        row[x].push_back(y);
        col[y].push_back(x);
        ++rowCnt[x];
        ++colCnt[y];
    }

    vector<char> deadRow(H, 0), deadCol(W, 0);

    int Q; cin >> Q;
    while (Q--) {
        int type, a;
        cin >> type >> a;
        --a;

        if (type == 1) {
            cout << rowCnt[a] << '\n';
            if (deadRow[a]) continue;
            deadRow[a] = 1;

            for (int y : row[a]) {
                if (!deadCol[y]) {
                    colCnt[y]--;
                }
            }
            rowCnt[a] = 0;
        } else {
            cout << colCnt[a] << '\n';
            if (deadCol[a]) continue;
            deadCol[a] = 1;

            for (int x : col[a]) {
                if (!deadRow[x]) {
                    rowCnt[x]--;
                }
            }
            col[a].clear();
            colCnt[a] = 0;
        }
    }

    return 0;
}
