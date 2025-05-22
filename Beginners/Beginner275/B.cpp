#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MOD = 998244353;
    long long A, B, C, D, E, F; cin >> A >> B >> C >> D >> E >> F;
    A%=MOD; B%=MOD; C%=MOD; D%=MOD; E%=MOD; F%=MOD;

    long long val1 = (A * B) % MOD; val1 = (val1 * C) % MOD;
    long long val2 = (D * E) % MOD; val2 = (val2 * F) % MOD;
    long long ans = (val1 - val2) % MOD;

    if (ans < 0) ans += MOD;
    cout << ans << endl;

    return 0;
}
