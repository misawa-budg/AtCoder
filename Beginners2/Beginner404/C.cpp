#include <bits/stdc++.h>
#include "atcoder/dsu.hpp"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> deg(N + 1, 0);
    atcoder::dsu uf(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        deg[a]++; deg[b]++;
        uf.merge(a, b);
    }

    if (N != M) {
        cout << "No\n";
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        if (deg[i] != 2) {
            cout << "No\n";
            return 0;
        }
    }

    int root = uf.leader(1);
    for (int i = 2; i <= N; i++) {
        if (uf.leader(i) != root) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";

    return 0;
}
