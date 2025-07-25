#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;
    int index = S.rfind('.');
    cout << S.substr(index + 1, S.size()) << endl;

    return 0;
}
