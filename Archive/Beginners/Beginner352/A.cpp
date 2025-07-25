#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;

    if (X < Z && Z < Y) cout << "Yes\n";
    else if (Y < Z && Z < X) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
