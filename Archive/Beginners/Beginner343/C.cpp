#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N; cin >> N;
    long long ans = 0;

    for (long long x = 1; x * x * x <= N; x++) {
        long long cube = x * x * x;
        string s = to_string(cube);
        int length = s.size();
        bool isPalindrome = true;
        for (int i = 0; i < length / 2; i++) {
            if (s[i] != s[length - 1 - i]) {
                isPalindrome = false;
                break;
            }
        }
        // string t = s;
        // reverse(t.begin(), t.end());
        // if (s == t) isPalindrome = true;
        if (isPalindrome) ans = max(ans, cube);
    }

    cout << ans << endl;

    return 0;
}
