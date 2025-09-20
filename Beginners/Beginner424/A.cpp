#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c; cin >> a >> b >> c;

    bool ok = true;
    if (a == b || b == c || c == a) {
        int longest = max({a, b, c});
        int sum = a + b + c;
        if (longest * 2 > sum) ok = false;
    } else {
        ok = false;
    }

    cout << (ok ? "Yes" : "No") << "\n";

    return 0;
}
