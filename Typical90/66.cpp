#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> L(N), R(N);
    for (int i = 0; i < N; ++i) {
        cin >> L[i] >> R[i];
    }

    double total = 0.0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            long long total_patterns = (long long)(R[i] - L[i] + 1) * (R[j] - L[j] + 1);
            long long wanting_patterns = 0;

            for (int k = L[i]; k <= R[i]; k++) {
                int up = min(R[j], k - 1);
                if (up >= L[j]) {
                    wanting_patterns += (up - L[j] + 1);
                }
            }

            if (wanting_patterns > 0) {
                total += (double)wanting_patterns / total_patterns;
            }
        }
    }
    cout << fixed << setprecision(12) << total << '\n';

    return 0;
}
