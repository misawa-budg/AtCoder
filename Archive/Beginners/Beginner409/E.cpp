#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> electrons(N); for (int i = 0; i < N; i++) cin >> electrons[i];

    vector<vector<pair<int, int>>> tree(N);
    for (int i = 0; i < N-1; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        tree[u].emplace_back(v, w);
        tree[v].emplace_back(u, w);
    }

    // 典型90で部分木(dfs)の問題のもの
    long long ans = 0;
    auto dfs = [&](auto&& self, int node, int parent) -> long long {
        long long sum = electrons[node];
        for (auto& [child, cost] : tree[node]) {
            if (child == parent) continue;
            long long child_sum = self(self, child, node);
            ans += llabs(child_sum) * cost;
            sum += child_sum;
        }
        return sum;
    };

    dfs(dfs, 0, -1);
    cout << ans << endl;

    return 0;
}
