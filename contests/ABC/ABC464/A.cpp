#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;

    int ecount = 0, wcount = 0;
    for (char c : S) {
        if (c == 'E') ecount++;
        else wcount++;
    }

    if (ecount > wcount) cout << "East\n";
    else cout << "West\n";

    return 0;
}
