#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        long long px, py, qx, qy, rx, ry, sx, sy;
        cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;

        long long ax = qx - px;
        long long ay = qy - py;
        long long bx = sx - rx;
        long long by = sy - ry;

        long long cross = ax * by - ay * bx;

        if (cross != 0) {
            cout << "Yes\n";
        } else {
            long long vx = rx + sx - px - qx;
            long long vy = ry + sy - py - qy;

            __int128 dot = (__int128)ax * vx + (__int128)ay * vy;

            if (dot == 0) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }

    return 0;
}
