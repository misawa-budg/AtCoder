#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<vector<int>> rev_edges(N + 1);
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        rev_edges[y].push_back(x);
    }

    vector<bool> can_reach(N + 1, false);
    int Q; cin >> Q;
    while (Q--) {
        int query, v; cin >> query >> v;

        if (query == 1) {    
            if (can_reach[v]) continue;

            queue<int> q;
            can_reach[v] = true;
            q.push(v);
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                for (int next : rev_edges[cur]) {
                    if (can_reach[next]) continue;
                    can_reach[next] = true;
                    q.push(next);
                }
            }
        } else if (query == 2) {
            if (can_reach[v]) cout << "Yes\n";
            else cout << "No\n";
        }
    }

    return 0;
}
