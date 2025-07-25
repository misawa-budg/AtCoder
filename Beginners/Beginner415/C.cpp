#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        string S; cin >> S;

        int all = 1 << N;
        vector<bool> safe(all, true);
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '1') safe[i + 1] = false;
        }

        vector<bool> dp(all, false);
        dp[0] = true;

        for (int mask = 0; mask < all; mask++) {
            if (!dp[mask]) continue;

            for (int k = 0; k < N; k++) {
                if ((mask >> k) & 1) continue;
                int newMask = mask | (1 << k);
                if (safe[newMask]) dp[newMask] = true;
            }
        }

        cout << (dp[all - 1] ? "Yes\n" : "No\n");
    }

    return 0;
}
