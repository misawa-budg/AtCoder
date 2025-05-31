#include <bits/stdc++.h>
#include "atcoder/dsu.hpp"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<vector<pair<int, int>>> graph(N);
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        graph[u].emplace_back(w, v);
        graph[v].emplace_back(w, u);
    }

    int ans = 0;
    for (int bit = 29; bit >= 0; bit--) {
        atcoder::dsu uf(N);

        for (int u = 0; u < N; u++) {
            int target = ans | ((1 << bit) - 1);
            for (auto [w, v] : graph[u]) {
                if ((w | target) == target) {
                    uf.merge(u, v);
                }
            }
        }

        if (!uf.same(0, N - 1)) {
            ans |= (1 << bit);
        }
    }

    cout << ans << endl;

    return 0;
}
