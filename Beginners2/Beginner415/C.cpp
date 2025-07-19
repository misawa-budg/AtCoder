#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        string S; cin >> S;

        int all = 1 << N;
        vector<bool> dp(all, false);
        dp[0] = true;
        for (int med = 1; med < all; med++) {
            if (S[med - 1] == '1') continue;
            for (int i = 0; i < N; i++) {
                if ((med >> i) & 1) { // 含む場合
                    int prev = med ^ (1 << i);
                    if (dp[prev]) {
                        dp[med] = true;
                        break;
                    }
                }
            }
        }

        if (dp[all - 1]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
