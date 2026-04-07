#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        long long totalPower = 0;
        vector<pair<long long, long long>> deers(N);
        for (int i = 0; i < N; i++) {
            cin >> deers[i].first >> deers[i].second;
            totalPower += deers[i].second;
        }

        sort(deers.begin(), deers.end(), [&](auto x, auto y) {
            return x.first + x.second < y.first + y.second;
        });

        // P * (N - k) >= W * k
        // - P*k - W*k >= - P*N
        // (P + W) * k <= P * N
        
        long long ans = 0, total = 0;
        for (int i = 0; i < N; i++) {
            total += deers[i].first + deers[i].second;
            if (total <= totalPower) ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}
