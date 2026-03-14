#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, L, R; cin >> N >> L >> R;
    string S; cin >> S;

    long long ans = 0;
    vector<int> count(26, 0);

    for (int j = 0; j < N; ++j) {
        if (j - L >= 0) {
            count[S[j - L] - 'a']++;
        }
        
        if (j - R - 1 >= 0) {
            count[S[j - R - 1] - 'a']--;
        }
        
        ans += count[S[j] - 'a'];
    }

    cout << ans << "\n";

    return 0;
}
