#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, L; cin >> N >> M >> L;
    long long S, T; cin >> S >> T;
    vector<vector<pair<int, long long>>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        long long c; cin >> c;
        G[u].emplace_back(v, c);
    }

    vector<bool> ans(N, false);
    // cur, total_cost, move_count
    deque<tuple<int, long long, int>> s;
    s.emplace_back(0, 0, 0);
    while (!s.empty()) {
        auto [cur, total, count] = s.back();
        s.pop_back();

        if (count == L && (S <= total && total <= T)) {
            ans[cur] = true;
            continue;
        } else if (count == L || total > T) {
            continue;
        }

        for (auto [next, cost] : G[cur]) {
            if (total + cost > T) continue;
            s.emplace_back(next, total + cost, count + 1);
        }
    }

    for (int i = 0; i < N; i++) {
        if (ans[i]) cout << i + 1 << ' ';
    }
    cout << '\n';

    return 0;
}
