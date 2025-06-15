#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;
    vector<int> H(N); for (int i = 0; i < N; i++) cin >> H[i];

    vector<long long> dp(N, LLONG_MAX);
    dp[0] = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= K && i - j >= 0; j++) {
            dp[i] = min(dp[i], dp[i - j] + abs(H[i] - H[i - j]));
        }
    }
    cout << dp[N - 1] << endl;

    return 0;
}
