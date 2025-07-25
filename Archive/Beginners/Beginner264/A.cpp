#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, R; cin >> L >> R;
    string S = "atcoder";
    cout << S.substr(L - 1, R - L + 1) << '\n';

    return 0;
}
