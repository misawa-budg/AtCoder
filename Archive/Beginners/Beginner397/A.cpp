#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    float X;
    cin >> X;

    int ans = 0;
    if (X >= 38) ans = 1;
    else if (X < 37.5) ans = 3;
    else ans = 2;

    cout << ans << endl;

    return 0;
}
