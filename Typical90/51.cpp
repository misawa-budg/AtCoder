#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; long long P; cin >> N >> K >> P;
    vector<long long> A(N); for (int i = 0; i < N; ++i) cin >> A[i];

    vector<vector<long long>> sumL(K + 1), sumR(K + 1);
    int nL = N / 2, nR = N - nL;

    for (int bit = 0; bit < (1 << nL); bit++) {
        int cnt = __builtin_popcount(bit);
        if (cnt > K) continue;
        long long sum = 0;
        for (int i = 0; i < nL; i++) {
            if (bit & (1 << i)) {
                sum += A[i];
            }
        }
        if (sum <= P) sumL[cnt].push_back(sum);
    }

    for (int bit = 0; bit < (1 << nR); bit++) {
        int cnt = __builtin_popcount(bit);
        if (cnt > K) continue;
        long long sum = 0;
        for (int i = 0; i < nR; i++) {
            if (bit & (1 << i)) {
                sum += A[nL + i];
            }
        }
        if (sum <= P) sumR[cnt].push_back(sum);
    }

    for (auto &v : sumR) sort(v.begin(), v.end());

    long long ans = 0;
    for (int kL = 0; kL <= K; kL++) {
        int kR = K - kL;
        for (auto &sumL_val : sumL[kL]) {
            long long remain = P - sumL_val;
            ans += upper_bound(sumR[kR].begin(), sumR[kR].end(), remain) - sumR[kR].begin();
        }
    }

    cout << ans << endl;

    return 0;
}
