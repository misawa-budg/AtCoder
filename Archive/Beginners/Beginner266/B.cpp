#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const long long MOD = 998244353;
    long long N; cin >> N;
    long long ans = N % MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';

    return 0;
}
