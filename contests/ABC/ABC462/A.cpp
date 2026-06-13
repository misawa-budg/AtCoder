#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;
    for (int i = 0; i < S.length(); i++) {
        if ('0' <= S[i] && S[i] <= '9') cout << S[i];
    }
    cout << '\n';

    return 0;
}
