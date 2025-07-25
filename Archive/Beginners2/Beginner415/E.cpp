#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    vector<vector<long long>> A(H, vector<long long>(W));
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> A[i][j];

    vector<long long> P(H + W - 1);
    for (int i = 0; i < P.size(); i++) cin >> P[i];

    long long low = 0, high = 1e18, ans = high;
    while (low <= high) {
        long long mid = (low + high) / 2;
        vector<vector<long long>> dp(H, vector<long long>(W, -1));
        bool possible = false;

        if (mid + A[0][0] >= P[0]) {
            dp[0][0] = mid + A[0][0] - P[0];

            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    if (i == 0 && j == 0) continue;
                    long long day = i + j;

                    long long up = -1, left = -1;
                    if (i - 1 >= 0 && dp[i - 1][j] != -1) {
                        if (dp[i - 1][j] + A[i][j] >= P[day])
                            up = dp[i - 1][j] + A[i][j] - P[day];
                    }
                    if (j - 1 >= 0 && dp[i][j - 1] != -1) {
                        if (dp[i][j - 1] + A[i][j] >= P[day])
                            left = dp[i][j - 1] + A[i][j] - P[day];
                    }
                    dp[i][j] = max(up, left);
                }
            }
            if (dp[H - 1][W - 1] >= 0) {
                possible = true;
            }
        }

        if (possible) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;

    return 0;
}
