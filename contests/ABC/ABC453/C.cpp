#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<long long> L(N); for (int i = 0; i < N; i++) cin >> L[i];

    int ans = 0;
    for (int bit = 0; bit < (1 << N); bit++) {
        int count = 0;
        long long cur = 1; 
        int sign = 1;
        for (int i = 0; i < N; i++) {
            if (bit & (1 << i)) {
                cur += L[i];
                if (cur > 0 && sign == 1) continue;
                else if (cur > 0 && sign == -1) {
                    sign = 1;
                    count++;
                }
            } else {
                cur -= L[i];
                if (cur <= 0 && sign == -1) continue;
                else if (cur <= 0 && sign == 1) {
                    sign = -1;
                    count++;
                }
            }
        }
        ans = max(ans, count);
    }

    cout << ans << '\n';

    return 0;
}
