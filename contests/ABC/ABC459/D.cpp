#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        string S; cin >> S;

        vector<int> occur(26, 0);
        for (char c : S) occur[c - 'a']++;

        int maxOccur = *max_element(occur.begin(), occur.end());

        if (maxOccur > (S.size() + 1) / 2) {
            cout << "No\n";
            continue;
        }

        cout << "Yes\n";

        string ans;
        char lastChar = '.';
        for (int i = 0; i < S.size(); i++) {
            
            char maxChar = '?';
            int maxOccur = 0;
            for (int j = 0; j < 26; j++) {
                if (char('a' + j) == lastChar) continue;
                if (maxOccur < occur[j]) {
                    maxChar = char('a' + j);
                    maxOccur = occur[j];
                }
            }

            ans += maxChar;
            lastChar = maxChar;
            occur[maxChar - 'a']--;
        }

        cout << ans << '\n';
    }

    return 0;
}
