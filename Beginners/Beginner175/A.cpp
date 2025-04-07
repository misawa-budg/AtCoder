#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int count = 0;
    if (s[1] == 'R') {
        count++;
        if (s[0] == 'R') {
            count++;
        }
        if (s[2] == 'R') {
            count++;
        }
    } else {
        if (s[0] == 'R') {
            count++;
        } else if (s[2] == 'R') {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
