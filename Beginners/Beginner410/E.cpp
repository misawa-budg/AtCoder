#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, H, M; cin >> N >> H >> M;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    // 絶対DP
    // dp[h] = m : 体力hでの最大魔力?
    vector<int> dp(H + 1, -1), tmp(H + 1, -1);
    dp[H] = M;

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        fill(tmp.begin(), tmp.end(), -1);
        for (int h = 0; h <= H; h++) {
            if (dp[h] == -1) continue;
            int m = dp[h];

            if (h >= A[i]) {
                tmp[h - A[i]] = max(tmp[h - A[i]], m);
            }

            if (m >= B[i]) {
                tmp[h] = max(tmp[h], m - B[i]);
            }
        }

        // どこにも行けなくなったら終了
        bool ok = false;
        for (int h = 0; h <= H; h++) {
            if (tmp[h] != -1) {
                ok = true;
                break;
            }
        }
        if (!ok) break;

        dp.swap(tmp);
        ans++;
    }

    cout << ans << endl;

    return 0;
}
