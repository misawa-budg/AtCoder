#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, T; cin >> S >> T;

    for (int i = 1; i < S.size(); i++) {
        if (isupper(S[i])) {
            if (T.find(S[i - 1]) == string::npos) {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";

    return 0;
}
