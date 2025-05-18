#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, T; cin >> S >> T;

    int ans = T.size();
    for (int i = 0; i < S.size(); i++) {
        if (S[i] != T[i]) {
            ans = i + 1;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
