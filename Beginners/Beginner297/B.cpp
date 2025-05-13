#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;

    bool ok = true;
    if (S.find('B') % 2 == S.rfind('B') % 2) ok = false;
    if (!(S.find('R') < S.find('K') && S.find('K') < S.rfind('R'))) ok = false;

    if (ok) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
