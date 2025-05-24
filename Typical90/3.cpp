#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int start, vector<vector<int>>& adj)
{
    vector<int> dist(adj.size(), -1);
    vector<bool> visited(adj.size(), false);
    dist[start] = 0; visited[start] = true;
    queue<int> q; q.push(start);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int next : adj[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }

    return dist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < N - 1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist1 = bfs(1, adj);
    int maxNode = max_element(dist1.begin(), dist1.end()) - dist1.begin();

    vector<int> dist2 = bfs(maxNode, adj);
    int ans = *max_element(dist2.begin(), dist2.end());

    cout << ans + 1 << endl;

    return 0;
}
