#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K; cin >> K;

    if (K % 9 != 0) {
        cout << "0\n";
        return 0;
    }

    const long long MOD = 1e9 + 7;
    vector<long long> dp(K + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= 9; j++) {
            if (i - j >= 0) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }

    cout << dp[K] << "\n";

    return 0;
}
