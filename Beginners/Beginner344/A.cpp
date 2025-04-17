#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;
    int x = S.find('|');
    int y = S.rfind('|');
    cout << S.substr(0, x) << S.substr(y+1) << endl;

    return 0;
}
