#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> X(Q), Y(Q);
    for (int i = 0; i < Q; i++) {
        cin >> X[i] >> Y[i];
    }

    sort(A.begin(), A.end(), [&](int x, int y) { return x < y; });

    for (int i = 0; i < Q; i++) {
        // X ... A[si] ... (X + Y - 1) + (ti - 1- si + 1) ... A[ti]
        // (A[ti] - X + 1) - (ti - si + 1) >= Y となる最小のtiを求める
        // (X + Y - 1) + (ti - si)が答え
        int si = lower_bound(A.begin(), A.end(), X[i]) - A.begin();

        int ng = si - 1, ok = N;
        while (ok - ng > 1) {
            int mid = (ng + ok) / 2;
            
            if ((A[mid] - X[i] + 1) - (mid - si + 1) >= Y[i]) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        int ti = ok;

        cout << (X[i] + Y[i] - 1) + (ti - si) << '\n';
    }

    return 0;
}
