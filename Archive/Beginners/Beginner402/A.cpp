#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;
    string ans;

    for (int i = 0; i < S.size(); i++) {
        if (isupper(S[i])) {
            ans += S[i];
        }
    }

    cout << ans << endl;

    return 0;
}
