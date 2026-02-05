#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        long long N; cin >> N;
        long long total = 0;
        vector<long long> R(N);
        for (long long i = 0; i < N; i++) {
            cin >> R[i];
            total += R[i];
        }

        for (long long i = 1; i < N; i++) {
            R[i] = min(R[i], R[i - 1] + 1);
        }

        for (long long i = N - 2; i >= 0; i--) {
            R[i] = min(R[i], R[i + 1] + 1);
        }

        for (long long i = 0; i < N; i++) {
            total -= R[i];
        }
        cout << total << '\n';
    }

    return 0;
}
