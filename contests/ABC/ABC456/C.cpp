#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;
    const long long MOD = 998244353;

    long long total = 0;
    long long cur = 1;

    for (int i = 1; i < S.length(); i++) {
        if (S[i] != S[i - 1]) {
            cur++;
        } else {
            long long pattern = (cur * (cur + 1) / 2) % MOD;
            total = (total + pattern) % MOD;
            cur = 1;
        }
    }

    long long pattern = (cur * (cur + 1) / 2) % MOD;
    total = (total + pattern) % MOD;

    cout << total << '\n';

    return 0;
}
