#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, Q; cin >> N >> Q;
    vector<long long> u(N), v(N);
    long long Umin=LLONG_MAX, Umax=LLONG_MIN, Vmin=LLONG_MAX, Vmax=LLONG_MIN;
    for (int i = 0; i < N; ++i) {
        long long x, y; cin >> x >> y;
        u[i] = x + y;
        v[i] = x - y;
        Umin = min(Umin, u[i]);
        Umax = max(Umax, u[i]);
        Vmin = min(Vmin, v[i]);
        Vmax = max(Vmax, v[i]);
    }

    for (;Q;Q--) {
        int index; cin >> index; index--;
        long long ans = 0;
        ans = max(ans, Umax - u[index]);
        ans = max(ans, u[index] - Umin);
        ans = max(ans, Vmax - v[index]);
        ans = max(ans, v[index] - Vmin);
        cout << ans << '\n';
    }

    return 0;
}
