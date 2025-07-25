#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D, P; cin >> N >> D >> P;
    vector<int> prices(N); for (int i = 0; i < N; i++) cin >> prices[i];
    sort(prices.begin(), prices.end(), greater<int>());
    vector<long long> dp(N + 1, LLONG_MAX);
    dp[0] = 0;

    for (int i = 1; i <= N; i++) {
        dp[i] = dp[i-1] + prices[i-1];

        if(i >= D){
            dp[i] = min(dp[i], dp[i-D] + P);
        } else {
            dp[i] = min(dp[i], (long long)P);
        }
    }

    cout << dp[N] << '\n';

    return 0;
}
