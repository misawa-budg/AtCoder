#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int D, F; cin >> D >> F;
    cout << 7 - ((D - F) % 7) << '\n';

    return 0;
}
