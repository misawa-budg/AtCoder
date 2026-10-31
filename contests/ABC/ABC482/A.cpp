#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;

    int count = 0;
    for (char c : S) {
        if (c == 'o') count++;
    }

    cout << (count % 2 == 1 ? "odd" : "even") << '\n';

    return 0;
}
