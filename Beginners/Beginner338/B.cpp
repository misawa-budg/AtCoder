#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;
    map<char, int> freq;
    for (char c : S) {
        freq[c]++;
    }

    int count = 0;
    char ans = 'a';
    for (auto &it : freq) {
        if (it.second > count) {
            count = it.second;
            ans = it.first;
        }
    }

    cout << ans << endl;

    return 0;
}
