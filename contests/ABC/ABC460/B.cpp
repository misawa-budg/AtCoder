#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        long long x1, x2, y1, y2, r1, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        long long xdiff = x2 - x1;
        long long ydiff = y2 - y1;

        long long cdiff = xdiff * xdiff + ydiff * ydiff;

        long long rsum = (r1 + r2) * (r1 + r2);
        long long rdiff = (r1 - r2) * (r1 - r2);

        if (rdiff <= cdiff && cdiff <= rsum) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
