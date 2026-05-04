#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;
    const long long MOD = 998244353;

    long long cur = 1;
    long long total = 0;
    for (int i = 1; i < S.length(); i++) {
        if (S[i] != S[i - 1]) {
            cur++;
        } else {
            total = (total + (cur * (cur + 1) / 2) % MOD) % MOD;
            cur = 1;
        }
    }

    total = (total + (cur * (cur + 1) / 2) % MOD) % MOD;

    cout << total << '\n';

    return 0;
}
