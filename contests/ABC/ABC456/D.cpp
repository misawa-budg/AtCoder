#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;
    long long A = 0, B = 0, C = 0;
    const long long MOD = 998244353;

    for (char c : S) {
        if (c == 'a') {
            A = (A + B + C + 1) % MOD;
        } else if (c == 'b') {
            B = (A + B + C + 1) % MOD;
        } else if (c == 'c') {
            C = (A + B + C + 1) % MOD;
        }
    }

    cout << (A + B + C) % MOD << '\n';

    return 0;
}
