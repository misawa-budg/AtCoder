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
        long long cur = 1;
        int sign = 1;
        int count = 0;

        for (int i = 0; i < N; i++) {
            if (bit & (1 << i)) {
                cur += L[i];
                if (sign == -1 && cur >= 1) {
                    count++;
                    sign = 1;
                }
            } else {
                cur -= L[i];
                if (sign == 1 && cur <= 0) {
                    count++;
                    sign = -1;
                }
            }
        }

        ans = max(ans, count);
    }
    
    cout << ans << '\n';

    return 0;
}
