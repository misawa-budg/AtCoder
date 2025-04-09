#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> coordinates(N);
    vector<long long> members(N);
    for (int i = 0; i < N; i++) cin >> coordinates[i];
    for (int i = 0; i < N; i++) cin >> members[i];

    vector<long long> dp(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        dp[i] = dp[i - 1] + members[i - 1];
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int left, right;
        cin >> left >> right;
        int left_index = lower_bound(coordinates.begin(), coordinates.end(), left) - coordinates.begin();
        int right_index = upper_bound(coordinates.begin(), coordinates.end(), right) - coordinates.begin() - 1;

        if (left_index > right_index) {
            cout << 0 << endl;
        } else {
            long long ans = dp[right_index + 1] - dp[left_index];
            cout << ans << endl;
        }
    }

    return 0;
}
