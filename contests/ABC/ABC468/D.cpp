#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;
    long long ans = 0;

    for (int i = 0; i < S.length(); i++) {
        int diff = 0;
        for (int r = 0; i - r >= 0 && i + r < S.length(); r++) {
            if (S[i - r] != S[i + r]) diff++;
            if (diff > 1) break;
            ans++;
        }
    }

    for (int i = 0; i < S.length() - 1; i++) {
        int diff = 0;
        for (int r = 0; i - r >= 0 && i + 1 + r < S.length(); r++) {
            if (S[i - r] != S[i + 1 + r]) diff++;
            if (diff > 1) break;
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
