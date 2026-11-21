#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M; cin >> N >> M;

    vector<int> to(M), color(M);
    vector<vector<int>> G(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v, c; cin >> u >> v >> c;
        to[i] = v; color[i] = c;
        G[u].push_back(i);
    }

    vector<bool> used(M, false);
    vector<int> visitCount(N + 1, 0), visitColor(N + 1, -1);

    queue<tuple<int, int, int>> q;
    q.push({1, 0, 0});
    while (!q.empty()) {
        auto [v, c, d] = q.front(); q.pop();

        if (v == N) {
            cout << d << endl;
            return 0;
        }

        if (visitCount[v] == 0) {
            visitCount[v] = 1;
            visitColor[v] = c;
        } else if (visitCount[v] == 1 && c != visitColor[v]) {
            visitCount[v] = 2;
        } else {
            continue;
        }

        for (int e : G[v]) {
            if (!used[e] && color[e] != c) {
                used[e] = true;
                q.push({to[e], color[e], d + 1});
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
