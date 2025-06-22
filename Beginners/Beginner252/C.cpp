#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<string> S(N); for (int i = 0; i < N; ++i) cin >> S[i];

    int ans = INT_MAX;
    for (int i = 0; i < 10; i++) {
        char target = '0' + i;

        vector<int> cnt(10, 0);
        for (const auto& s : S) {
            for (int j = 0; j < 10; j++) {
                if (s[j] == target) {
                    cnt[j]++;
                }
            }
        }

        int time = 0;
        for (int j = 0; j < 10; j++) {
            if (cnt[j] > 0) {
                int latest = (cnt[j] - 1) * 10 + j;
                time = max(time, latest);
            }
        }
        ans = min(ans, time);
    }
    cout << ans << endl;

    return 0;
}
