#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<long long> A(N), B(N), C(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    for (int i = 0; i < N; i++) cin >> C[i];

    vector<vector<long long>> dp(N + 1, vector<long long>(3, LLONG_MIN));

    dp[1][0] = A[0];
    for (int i = 2; i <= N; i++) {
        long long a = A[i-1], b = B[i-1], c = C[i-1];
        dp[i][0] = dp[i-1][0] + a;
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]) + b;
        dp[i][2] = max(dp[i-1][1], dp[i-1][2]) + c;
    }

    cout << dp[N][2] << '\n';

    return 0;
}
