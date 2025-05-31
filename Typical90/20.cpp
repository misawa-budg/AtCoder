#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c; cin >> a >> b >> c;

    __int128_t longA = a;
    __int128_t right = 1;
    for (int i = 0; i < b; i++) right *= c;

    if (longA < right) cout <<"Yes\n";
    else cout << "No\n";

    return 0;
}
