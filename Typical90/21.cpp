#include <bits/stdc++.h>
#include "atcoder/scc.hpp"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    atcoder::scc_graph g(N);

    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        g.add_edge(u, v);
    }

    long long ans = 0;
    auto scc = g.scc();
    for (auto& component: scc) {
        long long size = component.size();
        ans += size * (size - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}
