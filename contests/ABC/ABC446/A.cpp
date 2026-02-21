#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;
    S[0] = S[0] - 'A' + 'a';
    cout << "Of" << S << '\n';

    return 0;
}
