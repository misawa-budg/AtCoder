#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X, Y, Z; cin >> X >> Y >> Z;

    int ans = -1;
    if (Y < 0) {
        X = -X;
        Y = -Y;
        Z = -Z;
    }

    if (X < Y) {
        ans = abs(X);
    } else {
        if (Y < Z) {
            ans = -1;
        } else {
            ans = abs(Z) + abs(Z - X);
        }
    }

    cout << ans << endl;

    return 0;
}
