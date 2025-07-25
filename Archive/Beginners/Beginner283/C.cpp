#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;

    int ans = 0;
    while (S.size() > 0) {
        if (S[S.size() - 1] == '0' && S[S.size() - 2] == '0') {
            S.pop_back(); S.pop_back();
            ans++;
        } else {
            S.pop_back();
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
