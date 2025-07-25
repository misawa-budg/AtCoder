#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> S(8); for (int i = 0; i < 8; i++) cin >> S[i];

    string rows = "87654321";
    string columns = "abcdefgh";

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (S[i][j] == '*') {
                cout << columns[j] << rows[i] << endl;
                break;
            }
        }
    }

    return 0;
}
