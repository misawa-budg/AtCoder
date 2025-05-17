#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;

    long long ans = 0;
    for (int i = 0; i < S.size(); i++) {
        int num = S[i] - 'A' + 1;
        long long base = 1;
        for (int j = 0; j < S.size() - i - 1; j++) {
            base *= 26;
        }
        ans += num * base;
    }

    cout << ans << endl;

    return 0;
}
