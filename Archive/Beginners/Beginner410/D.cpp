#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<vector<pair<int, int>>> G(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b, w; cin >> a >> b >> w;
        G[a].emplace_back(b, w);
    }

    vector<vector<char>> visited(N + 1, vector<char>(1 << 10, 0));
    queue<pair<int, int>> q;
    visited[1][0] = 1;
    q.push({1, 0});

    while (!q.empty()) {
        auto [node, mask] = q.front(); q.pop();
        for (auto [next, w] : G[node]) {
            int next_mask = mask ^ w;
            if (!visited[next][next_mask]) {
                visited[next][next_mask] = 1;
                q.push({next, next_mask});
            }
        }
    }

    int ans = -1;
    for (int i = 0; i < (1 << 10); i++) {
        if (visited[N][i]) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
