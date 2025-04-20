#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S, M, L; cin >> N >> S >> M >> L;
    vector<int> dp(N + 12, INT_MAX);
    dp[0] = 0;
    for (int i = 6; i <= N + 11; i++) {
        if (i >= 6 && dp[i - 6] != INT_MAX) {
            dp[i] = min(dp[i], dp[i - 6] + S);
        }
        if (i >= 8 && dp[i - 8] != INT_MAX) {
            dp[i] = min(dp[i], dp[i - 8] + M);
        }
        if (i >= 12 && dp[i - 12] != INT_MAX) {
            dp[i] = min(dp[i], dp[i - 12] + L);
        }
    }

    int ans = INT_MAX;
    for (int i = N; i <= N + 11; i++) {
        ans = min(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}
