#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L1, R1, L2, R2; cin >> L1 >> R1 >> L2 >> R2;

    cout << max(0, min(R1, R2) - max(L1, L2)) << '\n';

    return 0;
}
