#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L; cin >> N >> L;
    const int MOD = 1e9 + 7;
    vector<long long> dp(N + 1, -1);
    dp[0] = 1;

    for (int i = 1; i <= N; i++) {
        if (i >= L) {
            dp[i] = (dp[i - 1] + dp[i - L]) % MOD;
        } else {
            dp[i] = dp[i - 1];
        }
    }

    cout << (dp[N] == -1 ? 0 : dp[N]) << '\n';

    return 0;
}
