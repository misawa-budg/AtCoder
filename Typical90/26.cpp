#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> color(N, -1); color[0] = 0;
    vector<int> C0, C1;
    queue<int> q; q.push(0);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        (color[u]) ? C1.push_back(u) : C0.push_back(u);
        for (int v : G[u]) {
            if (color[v] == -1) {
                color[v] = color[u] ^ 1;
                q.push(v);
            }
        }
    }

    if (C0.size() >= N / 2) {
        for (int i = 0; i < N / 2; i++) {
            cout << C0[i] + 1 << " ";
        }
    } else {
        for (int i = 0; i < N / 2; i++) {
            cout << C1[i] + 1 << " ";
        }
    }
    cout << endl;

    return 0;
}
