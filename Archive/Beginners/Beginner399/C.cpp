#include <bits/stdc++.h>
#include "atcoder/dsu.hpp"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    atcoder::dsu uf(N);
    int component = N;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;;

        if (!uf.same(u, v)) {
            uf.merge(u, v);
            component--;
        }
    }

    cout << M - (N - component) << endl;

    return 0;
}
