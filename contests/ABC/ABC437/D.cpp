#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<long long> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    sort(A.begin(), A.end());

    vector<long long> psA(N + 1, 0);
    for (int i = 0; i < N; i++) psA[i + 1] = psA[i] + A[i];

    const long long MOD = 998244353;
    long long result = 0;
    for (int i = 0; i < M; i++) {
        long long target = B[i];
        int border /* target以下の数 */ = lower_bound(A.begin(), A.end(), target) - A.begin();
        long long lower = (target * border - psA[border] + MOD) % MOD; 
        long long upper = (psA[N] - psA[border] - target * (N - border) + MOD) % MOD;
        result = (result + lower + upper) % MOD;
    }

    cout << result << '\n';

    return 0;
}
