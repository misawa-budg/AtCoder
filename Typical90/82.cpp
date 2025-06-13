#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;
unsigned long long mod_pow(long long a, long long b, long long m)
{
    long long p = 1, q = a;
    for (int i = 0; i < 30; i++) {
        if (b & (1LL << i)) {
            p = (p * q) % m;
        }
        q *= q; q %= m;
    }
    return p;
}

long long mod_inv(long long a, long long b, long long m)
{
    return (a * mod_pow(b, m - 2, m)) % m;
}

long long f(long long x)
{
    long long v1 = x % mod;
    long long v2 = (x + 1) % mod;
    long long v = v1 * v2 % mod;
    return mod_inv(v, 2, mod);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long L, R; cin >> L >> R;

    vector<unsigned long long> pow10(22);
    pow10[0] = 1;
    for (int i = 1; i <= 19; ++i) {
        pow10[i] = pow10[i - 1] * 10;
    }

    long long ans = 0;
    for (int i = 1; i <= 19; i++) {
        unsigned long long v1 = max(L, pow10[i - 1]);
        unsigned long long v2 = min(R, pow10[i] - 1);
        if (v1 > v2) continue;
        long long val = (f(v2) - f(v1 - 1) + mod) % mod;
        ans += 1LL * i * val;
        ans %= mod;
    }
    cout << ans << endl;

    return 0;
}
