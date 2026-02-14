#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;

    if (S[0] == S[S.size() - 1]) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
