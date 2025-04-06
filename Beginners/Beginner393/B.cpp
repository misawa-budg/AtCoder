#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'B') {
            int diff = 0;
            while (0 <= i - diff && i + diff < s.size()) {
                diff++;
                if (s[i - diff] == 'A' && s[i + diff] == 'C') {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}
