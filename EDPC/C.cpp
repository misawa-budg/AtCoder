#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N), B(N), C(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> C[i];
    }

    vector<vector<long long>> dp(N, vector<long long>(3, LLONG_MIN));
    dp[0][0] = A[0];
    dp[0][1] = B[0];
    dp[0][2] = C[0];

    for (int i = 1; i < N; i++) {
        if (dp[i - 1][0] != LLONG_MIN) dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + A[i];
        if (dp[i - 1][1] != LLONG_MIN) dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + B[i];
        if (dp[i - 1][2] != LLONG_MIN) dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + C[i];
    }

    cout << max({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]}) << '\n';

    return 0;
}
