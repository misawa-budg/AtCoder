#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B, C; cin >> A >> B >> C;

    long long ABgcd = __gcd(A, B);
    long long ABCgcd = __gcd(ABgcd, C);

    long long ans = 0;
    ans += A / ABCgcd - 1;
    ans += B / ABCgcd - 1;
    ans += C / ABCgcd - 1;

    cout << ans << endl;

    return 0;
}
