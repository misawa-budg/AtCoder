#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X; cin >> X;
    long long ans;
    if (X > 0) {
        if (X % 10 == 0) {
            ans = X / 10;
        } else {
            ans = X / 10 + 1;
        }
    } else {
        ans = X / 10;
    }
    cout << ans << endl;

    return 0;
}
