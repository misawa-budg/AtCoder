#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<long long> A(N); for (int i = 0; i < N; i++) cin >> A[i];
    vector<long long> cumulative_sum(N + 1);
    cumulative_sum[N] = 0;
    for (int i = N - 1; i >= 0; i--) {
        cumulative_sum[i] = cumulative_sum[i + 1] + A[i];
    }

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += A[i] * cumulative_sum[i + 1];
    }
    cout << ans << endl;

    return 0;
}
