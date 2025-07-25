#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A; cin >> A;
    if (400 % A != 0) {
        cout << -1 << endl;
        return 0;
    }

    cout << 400 / A << endl;

    return 0;
}
