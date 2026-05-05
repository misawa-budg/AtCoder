#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int A, B; cin >> A >> B;
        adj[A].push_back(B);
    }

    vector<bool> can(N + 1, false);
    queue<int> q;
    can[1] = true;
    q.push(1);

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (const int next : adj[cur]) {
            if (can[next]) continue;
            can[next] = true;
            q.push(next);
        }
    }

    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (can[i]) count++;
    }

    cout << count << '\n';

    return 0;
}
