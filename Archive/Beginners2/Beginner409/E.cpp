#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<long long> x(N); for (int i = 0; i < N; i++) cin >> x[i];
    vector<vector<pair<int, long long>>> adj(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    long long ans = 0;

    auto dfs = [&](auto& dfs, int v, int p) -> void {
        for (auto& [c, w] : adj[v]) {
            if (c == p) continue;
            dfs(dfs, c, v);
            ans += w * abs(x[c]);
            x[v] += x[c];
        }
    };

    dfs(dfs, 0, -1);
    cout << ans << endl;

    return 0;
}
