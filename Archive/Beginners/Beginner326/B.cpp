#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    for (int i = N; i <= 919; i++) {
        string s = to_string(i);
        if ((s[0]-'0') * (s[1]-'0') == (s[2]-'0')) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}
