#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;

    bool flag = true;
    for (int i = 1; i < S.size(); i++) {
        if (S[i] >= S[i - 1]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "Yes" << endl;
        return 0;
    } else {
        cout << "No" << endl;
        return 0;
    }



    return 0;
}
