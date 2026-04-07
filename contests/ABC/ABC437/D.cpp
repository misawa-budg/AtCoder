#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const long long MOD = 998244353;
    int N, M; cin >> N >> M;
    vector<long long> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];

    sort(A.begin(), A.end());
    vector<long long> psA(N+1, 0);
    for (int i = 0; i < N; i++) psA[i + 1] = psA[i] + A[i];

    long long res = 0;
    for (int i = 0; i < M; i++) {
        long long target = B[i];
        int border = lower_bound(A.begin(), A.end(), target) - A.begin();
        long long lower = (border * target - psA[border] + MOD) % MOD;
        long long upper = ((psA[N] - psA[border]) - target * (N - border) + MOD) % MOD;
        res = (res + lower + upper) % MOD;
    }

    cout << res << '\n';

    return 0;
}
