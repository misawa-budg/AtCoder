#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

long long power(long long base, long long exp) {
    long long result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, K; cin >> N >> K;

    long long ans = 0;
    if (N == 1) {
        ans = K % MOD;
    } else if (N == 2) {
        if (K < 2) ans = 0;
        else {
            ans = (K * (K - 1)) % MOD;
        }
    } else {
        if (K < 3) ans = 0;
        else {
            long long k0 = K;
            long long k1 = K - 1;
            long long k2 = K - 2;

            long long k2_pow = power(k2, N - 2);
            ans = (k0 * k1 % MOD * k2_pow) % MOD;
        }
    }
    cout << ans << endl;

    return 0;
}
