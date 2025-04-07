#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;

    for (char c : S) {
        if (c == ',') {
            cout << ' ';
        } else {
            cout << c;
        }
    }
    cout << endl;

    return 0;
}
