#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;
    vector<string> T = {"ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"};

    for (int i = 0; i < T.size(); i++) {
        if (S == T[i]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}
