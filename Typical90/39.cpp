#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<vector<int>> adj(N);
    for (int i = 0; i < N - 1; ++i) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> subtreeSize(N, 0);
    function<void(int, int)> dfs = [&](int u, int p) {
        subtreeSize[u] = 1;
        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u);
                subtreeSize[u] += subtreeSize[v];
            }
        }
    };

    dfs(0, -1);

    long long ans = 0;
    for (int u = 0; u < N; u++) {
        ans += 1LL * subtreeSize[u] * (N - subtreeSize[u]);
    }

    cout << ans << endl;

    return 0;
}
