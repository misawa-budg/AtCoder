#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string T, U; cin >> T >> U;

    for (int i = 0; i < T.size(); i++) {
        bool valid = true;
        for (int j = 0; j < U.size(); j++) {
            if (T[i + j] == '?') continue;
            if (T[i + j] != U[j]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << "Yes" << '\n';
            return 0;
        }
    }
    cout << "No" << '\n';

    return 0;
}
