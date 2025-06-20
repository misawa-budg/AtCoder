#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, T; cin >> S >> T;

    int ti = 0, si = 0;
    while (ti < T.size() && si < S.size()) {
        char t = T[ti], s = S[si];
        int tSt = ti, sSt = si;
        while (si < S.size() && S[si] == s) si++;
        while (ti < T.size() && T[ti] == t) ti++;
        int sCnt = si - sSt, tCnt = ti - tSt;

        if (t != s || sCnt > tCnt || (sCnt < 2 && tCnt > 1)) {
            cout << "No\n";
            return 0;
        }
    }

    if (si != S.size() || ti != T.size()) {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";

    return 0;
}
