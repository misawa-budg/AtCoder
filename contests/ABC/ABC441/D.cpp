#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M, L, S, T;
    cin >> N >> M >> L >> S >> T;
    vector<vector<pair<int, long long>>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        long long cost; cin >> cost;
        G[u].emplace_back(v, cost);
    }

    vector<bool> ok(N, false);

    // origin, total, count
    queue<tuple<int, long long, int>> q;
    q.push({ 0, 0, 0 });
    while (!q.empty()) {
        auto [origin, total, count] = q.front();
        q.pop();

        if (count == L && (S <= total && total <= T)) {
            ok[origin] = true;
            continue;
        } else if (count == L) continue;

        for (int i = 0; i < G[origin].size(); i++) {
            auto [next, cost] = G[origin][i];
            if (total + cost > T) continue;
            q.emplace(next, total + cost, count + 1);
        }
    }

    for (int i = 0; i < N; i++) {
        if (ok[i]) cout << i + 1 << ' ';
    } cout << '\n';

    return 0;
}
