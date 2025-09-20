#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<bool> required(N, false);
    vector<vector<int>> G(N);
    queue<int> q;

    for (int i = 0; i < N; i++) {
        int A, B; cin >> A >> B;
        if (A == 0 && B == 0) {
            required[i] = true;
            q.push(i);
        } else {
            A--; B--;
            G[A].push_back(i);
            if (A != B) G[B].push_back(i);
        }
    }

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int nv : G[v]) {
            if (required[nv]) continue;
            required[nv] = true;
            q.push(nv);
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) if (required[i]) ans++;
    cout << ans << '\n';

    return 0;
}
