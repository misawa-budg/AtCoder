#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;

    int a = 0, ab = 0;
    int ans = 0;

    for (char c : S) {
        if (c == 'A') a++;
        else if (c == 'B') {
            if (a > 0) {
                a--;
                ab++;
            }
        } else if (c == 'C') {
            if (ab > 0) {
                ab--;
                ans++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
