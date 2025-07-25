#include <bits/stdc++.h>
#include "atcoder/dsu.hpp"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    atcoder::dsu uf(N);

    if (M != N - 1) {
        cout << "No" << endl;
        return 0;
    }

    vector<int> deg(N, 0);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        deg[u]++;
        deg[v]++;
        uf.merge(u, v);
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (deg[i] > 2) {
            cout << "No" << endl;
            return 0;
        }
        if (deg[i] == 1) {
            count++;
        }
    }

    if (count != 2) {
        cout << "No" << endl;
        return 0;
    }

    if (uf.groups().size() == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
