#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N; cin >> N;
    N--;

    string ans;
    int digit;
    while (N > 0) {
        digit = N % 5;
        ans.push_back('0' + digit * 2);
        N /= 5;
    }
    reverse(ans.begin(), ans.end());

    if (ans.empty()) ans = "0";

    cout << ans << endl;

    return 0;
}
