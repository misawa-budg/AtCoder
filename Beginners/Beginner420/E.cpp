#include <bits/stdc++.h>
#include "atcoder/dsu.hpp"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;
    atcoder::dsu uf(N);
    vector<int> blackCount(N, 0);
    vector<bool> isBlack(N, false);

    for (int i = 0; i < Q; i++) {
        int op; cin >> op;
        if (op == 1) {
            int u, v; cin >> u >> v; u--; v--;
            int prevu = uf.leader(u);
            int prevv = uf.leader(v);
            if (prevu == prevv) continue;
            uf.merge(u, v);
            int r = uf.leader(u);
            blackCount[r] = blackCount[prevu] + blackCount[prevv];
        } else if (op == 2) {
            int v; cin >> v; v--;
            int r = uf.leader(v);
            if (isBlack[v]) {
                blackCount[r]--;
                isBlack[v] = false;
            } else {
                blackCount[r]++;
                isBlack[v] = true;
            }
        } else {
            int v; cin >> v; v--;
            int r = uf.leader(v);
            if (blackCount[r] > 0) {
                cout << "Yes" << "\n";
            } else {
                cout << "No" << "\n";
            }
        }
    }

    return 0;
}
