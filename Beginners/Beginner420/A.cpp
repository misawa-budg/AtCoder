#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X, Y; cin >> X >> Y;

    int res = X + Y;
    if (res >= 13) res -= 12;
    cout << res << endl;

    return 0;
}
