#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;
    vector<int> occur(26, 0);
    for (char c : S) {
        occur[c - 'a']++;
    }

    int maxoccur = 0;
    for (int i = 0; i < 26; i++) maxoccur = max(maxoccur, occur[i]);

    for (char c : S) {
        if (occur[c - 'a'] == maxoccur) continue;
        cout << c;
    }
    cout << '\n';

    return 0;
}
