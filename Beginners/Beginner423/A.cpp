#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X, C;
    cin >> X >> C;

    // (ans / 1000) * C + ans <= X
    // ans * C + 1000ans <= 1000X
    // ans * (C + 1000) <= 1000X
    // ans <= 1000X / (C + 1000)

    long long ans = X / (C + 1000);
    ans *= 1000;
    cout << ans << endl;

    return 0;
}
