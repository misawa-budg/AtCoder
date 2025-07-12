#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D; cin >> N >> D;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    map<int, int> counts;
    for (int i = 0; i < N; i++) {
        counts[A[i]]++;
    }

    if (D == 0) {
        cout << N - counts.size() << endl;
        return 0;
    }

    map<int, vector<int>> groups;
    for (const auto& [val, freq] : counts) {
        groups[val % D].push_back(val);
    }

    long long keep = 0;

    for (const auto& [rem, chain] : groups) {
        vector<long long> dp(chain.size() + 1, 0);
        dp[1] = counts[chain[0]];
        for (int i = 2; i <= chain.size(); i++) {
            if (chain[i - 1] - chain[i - 2] != D) {
                dp[i] = dp[i - 1] + counts[chain[i - 1]];
            } else {
                dp[i] = max(dp[i - 1], dp[i - 2] + counts[chain[i - 1]]);
            }
        }
        keep += dp[chain.size()];
    }
    cout << N - keep << endl;

    return 0;
}
