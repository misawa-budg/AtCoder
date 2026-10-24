#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, S, T; cin >> N >> M >> S >> T;
    vector<vector<int>> G(N + 1);
    vector<int> minDist(N + 1, INT_MAX);

    for (int i = 0; i < M; i++) {
        int A, B; cin >> A >> B;
        G[A].push_back(B);
        minDist[A] = min(minDist[A], B);
    }

    vector<int> dist(N + 1, INT_MAX);
    deque<pair<int, int>> dq;

    dist[S] = 0;
    dq.push_front({0, S});
    while (!dq.empty()) {
        auto [d, u] = dq.front(); dq.pop_front();
        if (d != dist[u]) continue;

        for (int v : G[u]) {
            int cost = (v == minDist[u] ? 0 : 1);

            if (dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;

                if (cost == 0) dq.push_front({dist[v], v});
                else dq.push_back({dist[v], v});
            }
        }
    }

    cout << (dist[T] == INT_MAX ? -1 : dist[T]) << '\n';

    return 0;
}
