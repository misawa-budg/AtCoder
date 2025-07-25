#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long D; cin >> D;

    long long ans = D;
    long long y = 2e6;
    for (long long x = 0; x <= 2e6; x++) {
        while (y > 0 && x * x + y * y > D) {
            y--;
        }
        ans = min(ans, abs(x * x + y * y - D));
        ans = min(ans, abs(x * x + (y + 1) * (y + 1) - D));
    }

    cout << ans << endl;

    return 0;
}
