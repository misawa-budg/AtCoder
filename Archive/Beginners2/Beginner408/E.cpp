#include <bits/stdc++.h>
#include "atcoder/dsu.hpp"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<tuple<int, int, int>> edges(N);
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        edges.emplace_back(u, v, w);
    }

    int ans = (1 << 30) - 1;
    for (int digit = 29; digit >= 0; digit--) {
        int potential = ans & ~(1 << digit);

        atcoder::dsu uf(N);
        for (const auto& [u, v, w] : edges) {
            if ((w | potential) == potential) {
                uf.merge(u, v);
            }
        }

        if (uf.same(0, N - 1)) {
            ans = potential;
        }
    }
    cout << ans << endl;

    return 0;
}
