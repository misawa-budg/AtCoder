#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;

    if (S[S.size() - 1] == 'e') {
        cout << S << "r\n";
    } else {
        cout << S << "er\n";
    }

    return 0;
}
