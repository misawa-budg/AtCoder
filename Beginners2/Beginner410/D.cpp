#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<vector<pair<int, int>>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b, w; cin >> a >> b >> w;
        a--; b--;
        G[a].emplace_back(b, w);
    }

    vector<vector<int>> dist(N, vector<int>(1 << 10, 0));
    dist[0][0] = 1;
    deque<pair<int, int>> dq;
    dq.emplace_back(0, 0);

    while (!dq.empty()) {
        auto [u, mask] = dq.front(); dq.pop_front();
        for (const auto& [v, w] : G[u]) {
            int newMask = mask ^ w;
            if (!dist[v][newMask]) {
                dist[v][newMask] = 1;
                dq.emplace_back(v, newMask);
            }
        }
    }

    for (int i = 0; i < dist[N - 1].size(); i++) {
        if (dist[N - 1][i] != 0) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}
