#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<vector<pair<int, int>>> seg(Q + 1);

    for (int i = 0; i < Q; i++) {
        int L, R, X;
        cin >> L >> R >> X;
        seg[X].push_back({L, R});
    }

    vector<int> imos(N + 2);

    for (int x = 1; x <= Q; x++) {
        if (seg[x].empty()) continue;

        sort(seg[x].begin(), seg[x].end());

        int L = seg[x][0].first;
        int R = seg[x][0].second;

        for (int j = 1; j < seg[x].size(); j++) {
            auto [l, r] = seg[x][j];

            if (l <= R + 1) R = max(R, r);
            else {
                imos[L]++;
                imos[R + 1]--;

                L = l;
                R = r;
            }
        }

        imos[L]++;
        imos[R + 1]--;
    }

    for (int i = 1; i <= N; i++) {
        imos[i] += imos[i - 1];

        if (i > 1) cout << ' ';
        cout << imos[i];
    }

    cout << '\n';

    return 0;
}
