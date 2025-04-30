#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string T, U; cin >> T >> U;

    bool match = true;
    for (int i = 0; i <= T.size() - U.size(); i++) {
        match = true;
        for (int j = 0; j < U.size(); j++) {
            if (T[i+j] == '?' || T[i+j] == U[j]) {
                continue;
            } else {
                match = false;
                break;
            }
        }
        if (match) break;
    }
    if (match) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
