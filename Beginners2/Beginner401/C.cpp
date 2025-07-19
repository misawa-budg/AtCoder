#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;
    const int MOD = 1e9;
    vector<long long> A(N + 1, 1);
    long long s = K;

    for (int i = K; i <= N; i++) {
        A[i] = s;
        s = (s - A[i - K] + MOD) % MOD;
        s += A[i];
        if (s >= MOD) s -= MOD;
    }

    cout << A[N] << endl;

    return 0;
}
