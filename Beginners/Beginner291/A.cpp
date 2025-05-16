#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;

    for (int i = 0; i < S.size(); i++) {
        if (isupper(S[i])) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    return 0;
}
