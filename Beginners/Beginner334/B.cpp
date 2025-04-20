#include <bits/stdc++.h>
using namespace std;

long long floor(long long x, long long y)
{
    long long q = x / y;
    long long r = x % y;
    if (r < 0) q--;
    return q;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, M, L, R; cin >> A >> M >> L >> R;

    R -= A; L -= A;
    long long ans = max(0LL, floor(R, M) - floor(L + M - 1, M) + 1);

    cout << ans << endl;

    return 0;
}
