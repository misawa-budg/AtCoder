#include <bits/stdc++.h>
using namespace std;

long long sqrt_ull(long long x) {
    long long r = sqrtl((long double)x);
    while ((__int128)(r + 1) * (r + 1) <= x) r++;
    while ((__int128)r * r > x) r--;
    return r;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N; cin >> N;

    long long ans = sqrt_ull(N / 2) + sqrt_ull(N / 4);
    cout << ans << endl;

    return 0;
}
