#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long L, R, D, U; cin >> L >> R >> D >> U;
    long long total = 0;

    for (long long x = L; x <= R; x++) {
        long long k = abs(x);

        // in a rowの範囲
        long long middle_min = max(D, -k);
        long long middle_max = min(U, k);
        if (middle_min <= middle_max && k % 2 == 0) 
            total += (middle_max - middle_min + 1);

        // 交互(下)
        long long lower_min = D;
        long long lower_max = min(U, -k - 1);
        if (lower_min <= lower_max) {
            if (lower_min % 2 != 0) lower_min++;
            if (lower_max % 2 != 0) lower_max--;
            if (lower_min <= lower_max) {
                total += (lower_max - lower_min) / 2 + 1;
            }
        }

        // 交互 (上)
        long long upper_min = max(D, k + 1);
        long long upper_max = U;
        if (upper_min <= upper_max) {
            if (upper_min % 2 != 0) upper_min++;
            if (upper_max % 2 != 0) upper_max--;
            if (upper_min <= upper_max) {
                total += (upper_max - upper_min) / 2 + 1;
            }
        }
    }
    cout << total << '\n';

    return 0;
}
