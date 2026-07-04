#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        long long X, Y, K; cin >> X >> Y >> K;

        long long ans = 0;
        while (X != Y) {
            if (X > Y) X /= K;
            else Y /= K;
            ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}
