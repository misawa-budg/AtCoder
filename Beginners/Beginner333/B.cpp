#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, T; cin >> S >> T;

    if (S[0] > S[1]) swap(S[0], S[1]);
    if (T[0] > T[1]) swap(T[0], T[1]);

    auto nextTo = [](char a, char b) {
        return (a - b == 1 || a - b == 4);
    };

    if (nextTo(S[1], S[0]) == nextTo(T[1], T[0])) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
