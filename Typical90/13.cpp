#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int start, const vector<vector<pair<int, int>>>& graph)
{
    int N = graph.size();
    vector<int> dist(N, INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (const auto& [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<vector<pair<int, int>>> graph(N);
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    auto dist = dijkstra(0, graph);
    auto rdist = dijkstra(N - 1, graph);

    for (int i = 0; i < N; i++) {
        cout << dist[i] + rdist[i] << endl;
    }
    
    return 0;
}