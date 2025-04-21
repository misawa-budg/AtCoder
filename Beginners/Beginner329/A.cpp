#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;
    for (int i = 0; i < S.size(); i++) {
        if (i) cout << " ";
        cout << S[i];
    }
    cout << endl;

    return 0;
}
