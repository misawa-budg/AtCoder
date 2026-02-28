#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<pair<long long, long long>> deer(N);
        long long totalP = 0;
        for (int i = 0; i < N; i++) {
            cin >> deer[i].first >> deer[i].second;
            totalP += deer[i].second;
        }

        // totalP = 総和
        // 1匹乗る -> totalP - P[i] && 負担+W[i]
        // totalP - (P[i] + W[i]) >= 0の間はok
        sort(deer.begin(), deer.end(), [&](auto x, auto y) {
            return (x.first + x.second) < (y.first + y.second);
        });

        int res = 0;
        for (int i = 0; i < N; i++) {
            totalP -= (deer[i].first + deer[i].second);
            if (totalP >= 0) res++;
            else break;
        }
        cout << res << '\n';
    }

    return 0;
}
