#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<int>> adj(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    map<int, int> count;
    int kind = 1;
    vector<bool> ans(N);

    auto dfs = [&](auto& self, int u, int p) -> void {
        count[A[u]]++;
        if (count[A[u]] == 2) kind++;

        ans[u] = (kind > 1);

        for (int v : adj[u]) {
            if (v != p) self(self, v, u);
        }

        if (count[A[u]] == 2) kind--;
        count[A[u]]--;
    };

    dfs(dfs, 0, -1);

    for (int i = 0; i < N; i++) {
        if (ans[i]) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
