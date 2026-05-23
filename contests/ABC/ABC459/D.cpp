#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        string S; cin >> S;
        int n = S.size();

        vector<int> count(26);
        for (char c : S) count[c - 'a']++;

        int maxCount = *max_element(count.begin(), count.end());

        if (maxCount > ((n + 1) / 2)) {
            cout << "No\n";
            continue;
        }
        
        cout << "Yes\n";

        vector<pair<int, char>> freq;
        for (int i = 0; i < 26; i++) {
            freq.push_back({count[i], char('a' + i)});
        }

        sort(freq.rbegin(), freq.rend());

        string chars;
        for (auto [num, c] : freq) chars += string(num, c);

        string ans(n, '.');
        int idx = 0;

        for (int i = 0; i < n; i += 2) ans[i] = chars[idx++];
        for (int i = 1; i < n; i += 2) ans[i] = chars[idx++];

        cout << ans << '\n';
    }

    return 0;
}
