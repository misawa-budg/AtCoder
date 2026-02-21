#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<long long> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    unordered_map<long long, int> dp;

    int ans = 0;
    for (long long x : A) {
        int prev = 0; // 前の数字が存在しない
        auto it = dp.find(x - 1);
        if (it != dp.end()) prev = it->second; // 前の数字の最大長

        int cur = prev + 1;
        auto it2 = dp.find(x);
        if (it2 == dp.end()) dp[x] = cur;
        else it2->second = max(it2->second, cur);
        
        ans = max(ans, dp[x]);
    }

    cout << ans << '\n';

    return 0;
}
