#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> H(N); for (int i = 0; i < N; i++) cin >> H[i];

    vector<long long> dp(N, LLONG_MAX);
    dp[0] = 0;
    for (int i = 1; i < N; i++) {
        if (i >= 1) {
            dp[i] = min(dp[i], dp[i - 1] + abs(H[i] - H[i - 1]));
        }
        if (i >= 2) {
            dp[i] = min(dp[i], dp[i - 2] + abs(H[i] - H[i - 2]));
        }
    }
    cout << dp[N - 1] << '\n';

    return 0;
}
