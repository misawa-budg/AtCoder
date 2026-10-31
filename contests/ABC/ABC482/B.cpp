#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> S(5);
    for (int i = 0; i < 5; i++) cin >> S[i];

    vector<int> rCount(5, 0), cCount(5, 0), xCount(2, 0);
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            if (S[r][c] == 'o') {
                if (r == c) xCount[0]++;
                if (4 - r == c) xCount[1]++;
                rCount[r]++;
                cCount[c]++;
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < 5; i++) {
        ans = min(ans, 5 - rCount[i]);
        ans = min(ans, 5 - cCount[i]);
    }

    for (int i = 0; i < 2; i++) ans = min(ans, 5 - xCount[i]);

    cout << ans << '\n';

    return 0;
}
