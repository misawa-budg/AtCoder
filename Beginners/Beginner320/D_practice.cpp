#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<vector<tuple<int, long long, long long>>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int from, to, X, Y;
        cin >> from >> to >> X >> Y;
        adj[from].emplace_back(to, X, Y);
        adj[to].emplace_back(from, -X, -Y);
    }

    vector<bool> visited(N + 1, false);
    vector<pair<long long, long long>> coords(N + 1, {LLONG_MAX, LLONG_MAX});
    coords[1] = {0, 0};
    deque<int> dq;
    dq.push_back(1);
    visited[1] = true;

    while (!dq.empty()) {
        int point = dq.front(); dq.pop_front();
        for (const auto& [to, X, Y] : adj[point]) {
            if (!visited[to]) {
                visited[to] = true;
                coords[to].first = coords[point].first + X;
                coords[to].second = coords[point].second + Y;
                dq.push_back(to);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i]) {
            cout << coords[i].first << " " << coords[i].second << "\n";
        } else {
            cout << "undecidable\n";
        }
    }

    return 0;
}
