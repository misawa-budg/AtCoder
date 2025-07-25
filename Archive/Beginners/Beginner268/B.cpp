#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, T; cin >> S >> T;
    string prefix = T.substr(0, S.size());
    if (prefix == S) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
