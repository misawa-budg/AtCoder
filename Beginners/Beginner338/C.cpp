#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<long long> A(N), B(N), Q(N);
    long long maxQ = 0;
    for (int i = 0; i < N; ++i) {
        cin >> Q[i];
        maxQ = max(maxQ, Q[i]);
    }
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    long long ans = 0;
    for (int i = 0; i <= maxQ; i++) {
        long long cnt = LLONG_MAX;
        for (int j = 0; j < N; j++) {
            if (A[j] * i > Q[j]) {
                cnt = LLONG_MIN;
                break;
            } else if (B[j] > 0){
                cnt = min(cnt, (Q[j] - A[j] * i) / B[j]);
            }
        }
        ans = max(ans, (long long)cnt + i);
    }

    cout << ans << endl;

    return 0;
}
