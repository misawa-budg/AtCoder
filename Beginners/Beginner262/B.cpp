#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<set<int>> adf(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adf[u].insert(v);
        adf[v].insert(u);
    }

    int ans = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                if (adf[i].count(j) && adf[j].count(k) && adf[k].count(i)) {
                    ans++;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
