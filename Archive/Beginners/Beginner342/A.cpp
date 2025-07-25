#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;

    char main = (S[0] == S[1]) ? S[0] : S[2];

    for (int i = 0; i < S.size(); i++) {
        if (S[i] != main) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    return 0;
}
