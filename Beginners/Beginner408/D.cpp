#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        string S; cin >> S;

        long long all1 = 0, longest1 = 0, cur = 0;
        for (char c : S) {
            long long sign;
            if (c == '1') {
                sign = 1;
                all1++;
            } else {
                sign = -1;
            }
            cur = max(sign, cur + sign);
            longest1 = max(longest1, cur);
        }
        cout << all1 - longest1 << endl;
    }

    return 0;
}
