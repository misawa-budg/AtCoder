#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;

    for (; T--; ) {
        int N; cin >> N;
        string S; cin >> S;

        int left = 0;
        while (left + 1 < S.size() && S[left] <= S[left + 1]) left++;

        char start = S[left];
        int right = left + 1;
        while (right < S.size() && S[right] <= start) right++;

        string ans;
        ans += S.substr(0, left);
        ans += S.substr(left + 1, right - (left + 1));
        ans += start;
        ans += S.substr(right);

        cout << ans << endl;
    }

    return 0;
}
