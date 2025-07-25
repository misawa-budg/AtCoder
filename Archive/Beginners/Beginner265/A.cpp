#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X, Y, N; cin >> X >> Y >> N;

    int ans = 0;
    if (3 * X > Y) {
        ans += (N / 3) * Y;
        ans += (N % 3) * X;
    } else {
        ans = X * N;
    }

    cout << ans << '\n';

    return 0;
}
