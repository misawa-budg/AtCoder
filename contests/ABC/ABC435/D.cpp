#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<vector<int>> revG(N);
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y; x--; y--;
        revG[y].push_back(x);
    }

    vector<bool> visited(N, false);
    queue<int> q;

    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int query; cin >> query;
        int v; cin >> v; v--;
        if (query == 1) {
            if (visited[v]) continue;

            q.push(v);
            while (!q.empty()) {
                int u = q.front();
                q.pop();

                visited[u] = true;

                for (int n : revG[u]) {
                    if (!visited[n]) 
                        q.push(n);
                }
            }
        } else if (query == 2) {
            if (visited[v]) cout << "Yes\n";
            else cout << "No\n";
        }
    }

    return 0;
}
