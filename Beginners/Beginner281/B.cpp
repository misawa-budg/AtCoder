#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;
    bool ok = true;

    if (S.size() != 8) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 0; i < S.size(); i++) {
        if (i == 0 || i == S.size() - 1) {
            if (!isupper(S[i])) {
                ok = false;
                break;
            }
        } else if (i == 1) {
            if (S[i] < '1' || S[i] > '9') {
                ok = false;
                break;
            }
        } else {
            if (S[i] < '0' || S[i] > '9') {
                ok = false;
                break;
            }
        }
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
