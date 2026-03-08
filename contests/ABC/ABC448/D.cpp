#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N); 
    vector<int> val;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        val.push_back(A[i]);
    }

    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    for (int i = 0; i < N; i++) {
        A[i] = lower_bound(val.begin(), val.end(), A[i]) - val.begin();
    }
    
    vector<int> count(val.size(), 0);
    vector<vector<int>> G(N);
    for (int i = 0; i < N-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<bool> ans(N, false);
    int dup = 0;
    auto dfs = [&](auto& self, int u, int p) -> void {
        count[A[u]]++;
        if (count[A[u]] == 2) dup++;

        ans[u] = (dup > 0);

        for (int v : G[u]) {
            if (v != p) self(self, v, u);
        }

        if (count[A[u]] == 2) dup--;
        count[A[u]]--;
    };

    dfs(dfs, 0, -1);

    for (int i = 0; i < N; i++) {
        if (ans[i]) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
