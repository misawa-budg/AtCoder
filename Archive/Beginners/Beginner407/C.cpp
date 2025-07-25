#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;

    long long ans = 0;
    long long offset = 0;

    for (int i = S.size() - 1; i >= 0; i--) {
        int target = S[i] - '0';
        target = (target - offset + 10) % 10;

        offset += target;
        offset %= 10;
        ans += target;
        ans++;
    }

    cout << ans << endl;

    return 0;
}
