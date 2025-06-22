#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c; cin >> a >> b >> c;
    bool median = false;
    if ((a <= b && b <= c) || (c <= b && b <= a)) {
        median = true;
    }

    cout << (median ? "Yes" : "No") << '\n';

    return 0;
}
