#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, N; cin >> H >> W >> N;
    vector<vector<int>> rows(H + 1, vector<int>());
    vector<vector<int>> cols(W + 1, vector<int>());
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        rows[x].push_back(i);
        cols[y].push_back(i);
    }
    vector<char> doneRows(H + 1, 0), doneCols(W + 1, 0);
    vector<char> threw(N, 0);


    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int query; cin >> query;
        int ans = 0;
        if (query == 1) {
            int x; cin >> x;
            if (doneRows[x]) ans = 0;
            else {
                for (auto& idx : rows[x]) {
                    if (!threw[idx]) {
                        threw[idx] = 1;
                        ans++;
                    }
                }
                doneRows[x] = 1;
            }
        } else {
            int y; cin >> y;
            if (doneCols[y]) ans = 0;
            else {
                for (auto& idx : cols[y]) {
                    if (!threw[idx]) {
                        threw[idx] = 1;
                        ans++;
                    }
                }
                doneCols[y] = 1;
            }
        }
        cout << ans << '\n';
    }


    return 0;
}
