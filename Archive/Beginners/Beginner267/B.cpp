#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;

    if (s[0] == '1') {
        cout << "No\n";
        return 0;
    }

    vector<int> colSum(7, 0);
    vector<int> lane = {3, 2, 4, 1, 3, 5, 0, 2, 4, 6};
    for (int i = 0; i < 10; i++) {
        if (s[i] == '1') colSum[lane[i]]++;
    }

    bool ok = false;
    for (int i = 0; i < 7; i++) {
        for (int j = i + 2; j < 7; j++) {
            if (colSum[i] == 0 || colSum[j] == 0) continue;
            bool empty = false;
            for (int k = i + 1; k < j; k++) {
                if (colSum[k] == 0) {
                    empty = true;
                    break;
                }
            }
            if (empty) {
                ok = true;
                break;
            }
        }
    }

    if (ok) cout << "Yes\n";
    else cout << "No\n";


    return 0;
}
