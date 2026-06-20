#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X, Y; cin >> X >> Y;
    if (16 * Y == 9 * X) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
