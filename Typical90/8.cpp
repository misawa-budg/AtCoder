#include <bits/stdc++.h>
using namespace std;

const string T = "atcoder";

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string S; cin >> S;

    vector<vector<int>> dp(N + 1, vector<int>(T.size() + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= T.size(); j++) {
            dp[i + 1][j] += dp[i][j];

            if (j < T.size() && S[i] == T[j]) {
                dp[i + 1][j + 1] += dp[i][j];
            }
            dp[i + 1][j] %= 1000000007;
        }
    }

    cout << dp[N][T.size()] << '\n';

    return 0;
}
