#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long H, W; cin >> H >> W;
    // 25 <= W / (0.01H * 0.01H)
    // 25 <= 10000 W / H * H
    // H * H * 25 <= 10000 *W

    if (1LL * H * H * 25 <= 10000 * W) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
