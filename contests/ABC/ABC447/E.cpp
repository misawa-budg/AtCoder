#include <bits/stdc++.h>
#include "atcoder/dsu.hpp"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const long long MOD = 998244353;
    int N, M; cin >> N >> M;
    vector<pair<int, int>> E(M + 1);
    for (int i = 1; i <= M; i++) {
        cin >> E[i].first >> E[i].second;
        E[i].first--; E[i].second--;
    }

    // N個 → (残したい順に結合) → 2個
    atcoder::dsu d(N);
    int elements = N;

    // コストが大きいものは残したい
    for (int i = M; i >= 1; i--) {
        int u = E[i].first, v = E[i].second;

        if (!d.same(u, v) && elements > 2) {
            d.merge(u, v);
            elements--;
        }
    }

    long long ans = 0;
    long long num = 2;
    for (int i = 1; i <= M; i++) {
        int u = E[i].first, v = E[i].second;

        // 削除済
        if (!d.same(u, v)) {
            ans = (ans + num) % MOD;
        }
        num = (num * 2) % MOD;
    }

    cout << ans << '\n';

    return 0;
}
