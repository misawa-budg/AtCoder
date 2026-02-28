#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, T; cin >> S >> T;

    string S_woA = "", T_woA = "";
    vector<int> cS, cT;

    int curA = 0;
    for (char c : S) {
        if (c == 'A') curA++;
        else {
            S_woA += c;
            cS.push_back(curA);
            curA = 0;
        }
    }
    cS.push_back(curA);

    curA = 0;
    for (char c : T) {
        if (c == 'A') curA++;
        else {
            T_woA += c;
            cT.push_back(curA);
            curA = 0;
        }
    }
    cT.push_back(curA);

    if (S_woA != T_woA) {
        cout << -1 << '\n';
        return 0;
    }

    // 'A'の連続区間の差
    long long ans = 0;
    for (int i = 0; i < cS.size(); i++) {
        ans += abs(cS[i] - cT[i]);
    }
    cout << ans << '\n';

    return 0;
}
