#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, W; cin >> N >> W;
    vector<int> weights(N);
    vector<long long> values(N);

    for (int i = 0; i < N; ++i) {
        cin >> weights[i] >> values[i];
    }

    vector<long long> dp(W + 1, LLONG_MIN);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = W; j >= weights[i]; j--) {
            if (dp[j - weights[i]] != LLONG_MIN) {
                dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';

    return 0;
}