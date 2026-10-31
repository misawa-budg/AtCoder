
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    vector<long long> X(N);
    for (int i = 0; i < N; i++) cin >> X[i];

    for (int k = 0; k < N; k++) {
        long long ans = (X[N - 1] - X[0]) / 2;

        if (k > 0) {
            long long left = (X[k] - X[0]) / 2;
            long long right = (X[N - 1] - X[k - 1]) / 2;

            long long time = max(left, right);
            ans = min(ans, time);
        }

        if (k < N - 1) {
            long long left = (X[k + 1] - X[0]) / 2;
            long long right = (X[N - 1] - X[k]) / 2;

            long long time = max(left, right);
            ans = min(ans, time);
        }

        cout << ans << '\n';
    }

    return 0;
}
