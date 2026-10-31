
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, N, Q;
    cin >> H >> W >> N >> Q;

    vector<int> R(N), C(N);
    for (int i = 0; i < N; i++) cin >> R[i] >> C[i];

    sort(R.begin(), R.end());
    sort(C.begin(), C.end());

    while (Q--) {
        int t, l, r;
        cin >> t >> l >> r;

        const auto &v = (t == 1 ? R : C);

        auto left = lower_bound(v.begin(), v.end(), l);
        auto right = upper_bound(v.begin(), v.end(), r);

        cout << right - left << '\n';
    }

    return 0;
}
