#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;

    int ans = 1;
    for (int i = 0; i < S.size(); i++) {
        for (int j = i + 1; j < S.size(); j++) {
            string sub = S.substr(i, j - i + 1);

            bool isPalindrome = true;
            for (int k = 0; k < sub.size(); k++) {
                if (sub[k] != sub[sub.size() - k - 1]) {
                    isPalindrome = false;
                    break;
                }
            }

            if (isPalindrome) {
                ans = max(ans, (int)sub.size());
            }
        }
    }
    cout << ans << endl;

    return 0;
}
