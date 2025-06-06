#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S; cin >> N >> S;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    vector<vector<bool>> dp(N + 1, vector<bool>(S + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= S; j++) {
            if (j >= A[i - 1]) {
                if (dp[i - 1][j - A[i - 1]]) {
                    dp[i][j] = true;
                }
            }
            if (j >= B[i - 1]) {
                if (dp[i - 1][j - B[i - 1]]) {
                    dp[i][j] = true;
                }
            }
        }
    }

    if (!dp[N][S]) {
        cout << "Impossible" << endl;
        return 0;
    } else {
        string ans = "";
        long long curPrice = S;
        for (int i = N; i > 0; i--) {
            if (curPrice >= A[i - 1] && dp[i - 1][curPrice - A[i - 1]]) {
                ans += 'A';
                curPrice -= A[i - 1];
            } else if (curPrice >= B[i - 1] && dp[i - 1][curPrice - B[i - 1]]) {
                ans += 'B';
                curPrice -= B[i - 1];
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }


    return 0;
}
