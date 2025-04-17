#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;

    bool isAllow = true;
    for (int i = 0; i < S.size(); i++) {
        if (!i) {
            if (S[i] != '<') {
                isAllow = false;
                break;
            }
        } else if (i == S.size() - 1) {
            if (S[i] != '>') {
                isAllow = false;
                break;
            }
        } else {
            if (S[i] != '=') {
                isAllow = false;
                break;
            }
        }
    }

    if (isAllow) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
