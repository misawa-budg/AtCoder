#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<long long> L(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i];
        L[i] *= 2;
    }

    int result = 0;
    for (int bit = 0; bit < (1 << N); bit++) {
        long long cur = 1;
        int sign = 1, count = 0;
        for (int i = 0; i < N; i++) {
            if ((1 << i) & bit) cur += L[i];
            else cur -= L[i];

            if (sign * cur < 0) {
                count++;
                sign = -sign;
            }
        }
        result = max(result, count);
    }

    cout << result << '\n';

    return 0;
}
