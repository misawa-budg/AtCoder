#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;

    char target = 'A';
    for (int i = 0; i < S.size(); i++) {
        if (S[i] > target) {
            target = S[i];
        } else if (S[i] < target) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
