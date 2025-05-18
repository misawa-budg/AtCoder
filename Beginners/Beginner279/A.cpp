#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;

    int ans = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'v') ans++;
        if (S[i] == 'w') ans += 2;
    }

    cout << ans << endl;

    return 0;
}
