#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, H, M; cin >> N >> H >> M;
    vector<int> dp(H + 1, -1); // dp[H]=M : 体力Hの時の魔力M
    dp[H] = M;

    for (int i = 0; i < N; i++) {
        int A, B; cin >> A >> B;

        vector<int> new_dp(H + 1, -1);
        bool canDefeat = false;
        for (int h = 0; h <= H; h++) {
            if (dp[h] == -1) continue;

            if (h - A >= 0) {
                new_dp[h - A] = max(new_dp[h - A], dp[h]);
                canDefeat = true;
            }
            if (dp[h] - B >= 0) {
                new_dp[h] = max(new_dp[h], dp[h] - B);
                canDefeat = true;
            }
        }
        if (!canDefeat) {
            cout << i << endl;
            return 0;
        }
        dp = new_dp;
    }

    cout << N << endl;

    return 0;
}
