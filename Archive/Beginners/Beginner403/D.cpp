#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int> &B)
{
    vector dp(B.size() + 1, vector<int>(2, 0));
    for (int i = 1; i <= B.size(); i++) {
        dp[i][1] = dp[i - 1][0] + B[i - 1];
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
    }
    long long sum = 0;
    for (int i = 0; i < B.size(); i++) sum += B[i];
    return sum - max(dp[B.size()][0], dp[B.size()][1]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D; cin >> N >> D;
    vector<int> A(N); for (int i = 0; i < N; ++i) cin >> A[i];
    vector<int> count(1000001, 0); for (int i = 0; i < N; ++i) count[A[i]]++;

    if (D == 0) {
        long long ans = 0;
        for (int i = 0; i < 1000001; i++) {
            if (count[i] > 0) {
                ans += count[i] - 1;
            }
        }
        cout << ans << endl;
        return 0;
    }

    long long ans = 0;
    for (int i = 0; i < D; i++) {
        vector<int> B;
        for (int j = i; j < 1000001; j += D) {
            B.push_back(count[j]);
        }
        ans += solve(B);
    }
    cout << ans << endl;

    return 0;
}
