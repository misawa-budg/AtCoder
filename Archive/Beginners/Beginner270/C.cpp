#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X, Y; cin >> N >> X >> Y;
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans;
    function<int(int, int)> dfs = [&](int node, int parent) {
        if (node == Y) {
            ans.push_back(node);
            return true;
        }
        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;
            if (dfs(neighbor, node)) {
                ans.push_back(node);
                return true;
            };
        }
        return false;
    };

    dfs(X, -1);

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i < ans.size() - 1) cout << " ";
    } cout << endl;


    return 0;
}
