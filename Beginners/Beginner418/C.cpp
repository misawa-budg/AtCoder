#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;
    vector<long long> A(N); for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    vector<long long> B(Q); for (int i = 0; i < Q; i++) cin >> B[i];

    vector<long long> cumulative(N, 0);
    for (int i = 0; i < N; i++) {
        cumulative[i] = A[i];
        if (i > 0) cumulative[i] += cumulative[i - 1];
    }
    long long limit = *max_element(A.begin(), A.end());

    for (int i = 0; i < Q; i++) {
        long long diff = B[i];
        if (diff > limit) {
            cout << -1 << '\n';
            continue;
        }

        long long ans = 0;
        int idx = lower_bound(A.begin(), A.end(), diff) - A.begin();
        if (idx > 0) {
            long long before = cumulative[idx - 1];
            long long after = (diff - 1) * (N - idx);
            ans = before + after + 1;
        } else {
            ans = (diff - 1) * N + 1;
        }

        cout << ans << '\n';
    }

    return 0;
}
