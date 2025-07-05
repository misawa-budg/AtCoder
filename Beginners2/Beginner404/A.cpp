#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;

    for (char c = 'a'; c <= 'z'; ++c) {
        if (s.find(c) == string::npos) {
            cout << c << '\n';
            return 0;
        }
    }

    return 0;
}
