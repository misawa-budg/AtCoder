#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<long long> A(N), B(N), C(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    for (int i = 0; i < N; i++) cin >> C[i];

    // vector<long long> psA(N + 1, 0), psB(N + 1, 0), psC(N + 1, 0);
    // for (int i = 0; i < N; i++) {
    //     psA[i+1] = psA[i] + A[i];
    //     psB[i+1] = psB[i] + B[i];
    //     psC[i+1] = psC[i] + C[i];
    // }

    // long long ans = LLONG_MIN;
    // long long Amax = LLONG_MIN;

    // for (int y = 2; y < N; y++) {
    //     int x = y - 1;
    //     Amax = max(Amax, psA[x] - psB[x]);
    //     ans = max(ans, Amax + psB[y] - psC[y] + psC[N]);
    // }

    // cout << ans << '\n';
    
    vector<vector<long long>> dp(N, vector<long long>(3, LLONG_MIN));
    dp[0][0] = A[0];
    for (int i = 1; i < N; i++) {
        if (dp[i-1][0] != LLONG_MIN) 
            dp[i][0] = dp[i-1][0] + A[i];
        if (dp[i-1][0] != LLONG_MIN || dp[i-1][1] != LLONG_MIN)
            dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + B[i];
        if (dp[i-1][1] != LLONG_MIN || dp[i-1][2] != LLONG_MIN)
            dp[i][2] = max(dp[i-1][1], dp[i-1][2]) + C[i];
    }
    cout << dp[N-1][2] << '\n';

    return 0;
}
