#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string P; cin >> P;
    int L; cin >> L;

    cout << ((P.size() >= L) ? "Yes" : "No") << endl;

    return 0;
}
