
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long K, T; cin >> N >> K >> T;
    vector<long long> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    sort(A.begin(), A.end());

    long long ans = 0, end = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] > T) break;
        if (end < A[i]) {
            long long gap = A[i] - end;
            long long cnt = (gap + K - 1) / K;
            ans += cnt;
            end += cnt * K;
        }

        end = max(end, A[i] + K);
    }

    if (end < T) {
        long long gap = T - end;
        ans += (gap + K - 1) / K;
    }

    cout << ans << '\n';

    return 0;
}
