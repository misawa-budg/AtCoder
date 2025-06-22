#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;
    for (int i = 0; i < 6 / S.size(); i++) {
        cout << S;
    }
    cout << endl;

    return 0;
}
