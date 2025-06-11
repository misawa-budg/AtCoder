#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, Q; cin >> N >> Q;
    vector<long long> A(N); for (int i = 0; i < N; i++) cin >> A[i];
    vector<long long> diff(N - 1, 0);
    long long ans = 0;
    for (int i = 0; i < N-1; i++) {
        diff[i] = A[i+1] - A[i];
        ans += abs(diff[i]);
    }

    for (int i = 0; i < Q; i++) {
        long long l, r, v; cin >> l >> r >> v;
        l--; r--;
        if (l > 0) {
            long long old = diff[l-1];
            long long neu = old + v;
            ans += abs(neu) - abs(old);
            diff[l-1] = neu;
        }

        if (r < N-1) {
            long long old = diff[r];
            long long neu = old - v;
            ans += abs(neu) - abs(old);
            diff[r] = neu;
        }
        cout << ans << endl;
    }


    return 0;
}