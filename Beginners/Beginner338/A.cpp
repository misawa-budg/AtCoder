#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;

    for (int i = 0; i < S.size(); i++) {
        if (!i) {
            if (!isupper(S[i])) {
                cout << "No" << endl;
                return 0;
            }
        } else {
            if (!islower(S[i])) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;

    return 0;
}
