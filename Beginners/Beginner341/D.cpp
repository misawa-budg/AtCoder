#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M, K; cin >> N >> M >> K;

    long long ans = 0;

    long long l = 0, r = 1e18;
    while (l < r) {
        long long x = (l + r) / 2;
        long long y = x / N + (x / M) - 2 * (x / lcm(N, M));
        if (y < K) {
            l = x + 1;
        } else {
            r = x;
        }
    }

    ans = r;
    cout << ans << endl;

    return 0;
}
