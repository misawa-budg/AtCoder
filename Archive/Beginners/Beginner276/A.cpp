#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;
    if (S.rfind('a') != string::npos) {
        cout << S.rfind('a') + 1 << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
