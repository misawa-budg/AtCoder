#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char p, q; cin >> p >> q;

    vector<int> cumulativeDist = {0,3,4,8,9,14,23};

    cout << abs(cumulativeDist[p - 'A'] - cumulativeDist[q - 'A']) << endl;

    return 0;
}
