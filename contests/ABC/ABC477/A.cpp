#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char C; cin >> C;

    if (C == 'B') cout << 'Y';
    else if (C == 'Y') cout << 'R';
    else if (C == 'R') cout << 'B';
    cout << '\n';

    return 0;
}
