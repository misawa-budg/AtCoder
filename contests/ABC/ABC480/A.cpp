#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S1, S2; cin >> S1 >> S2;

    vector<string> S = {S1, S2};

    int fr, fc, sr, sc;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (S[i][j] == 'A') {
                fr = i;
                fc = j;
            }
            if (S[i][j] == 'D') {
                sr = i;
                sc = j;
            }
        }
    }

    bool ok = false;
    if (abs(fr - sr) + abs(fc - sc) == 1) ok = true;

    cout << (ok ? "Yes" : "No") << '\n';

    return 0;
}
