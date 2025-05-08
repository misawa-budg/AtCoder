#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> S(9, 0); for (int i = 1; i <= 8; ++i) cin >> S[i];

    bool flag = true;
    for (int i = 1; i <= 8; i++) {
        if (S[i - 1] > S[i]) {
            flag = false;
            break;
        } else if (!(100<=S[i]) || !(S[i]<=675)) {
            flag = false;
            break;
        } else if (S[i] % 25 != 0) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
