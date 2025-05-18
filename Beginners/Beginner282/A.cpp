#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K; cin >> K;

    string ans = "";
    for (char c = 'A'; c < 'A' + K; c++) {
        ans += c;
    }

    cout << ans << endl;

    return 0;
}
