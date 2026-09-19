#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string S; cin >> S;
    string T; cin >> T;

    for (int i = 0; i < (int)S.size(); i++) {
        if (T[i] == '*') continue;
        if (T[i] != S[i]) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";

    return 0;
}
