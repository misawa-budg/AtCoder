#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    long double L, X, Y, Q; cin >> T >> L >> X >> Y >> Q;
    long double PI = 3.14159265358979323846;

    for (int i = 0; i < Q; i++) {
        long double E; cin >> E;

        long double y = L / 2 * - sin(2 * PI * E / T);
        long double z = L / 2 - L / 2 * cos(2 * PI * E / T);

        long double xy = sqrt(X * X + (Y - y) * (Y - y));
        long double ans = atan2(z, xy) * 180 / PI;
        cout << fixed << setprecision(12) << ans << '\n';
    }

    return 0;
}
