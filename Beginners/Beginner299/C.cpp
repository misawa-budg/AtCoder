#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string S; cin >> S;

    if (S.find('-')==string::npos || S.find('o')==string::npos) {
        cout << -1 << endl;
        return 0;
    }

    int ans = 0, tmp = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'o') {
            tmp++;
        } else {
            ans = max(ans, tmp);
            tmp = 0;
        }
    }
    ans = max(ans, tmp);

    cout << ans << endl;

    return 0;
}
