#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;

    string T = S;
    bool ok = true;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '.' && ok) {
            T[i] = 'o';
            ok = false;
        } else if (S[i] == '#') {
            ok = true;
        }
    }
    cout << T << '\n';

    return 0;
}
