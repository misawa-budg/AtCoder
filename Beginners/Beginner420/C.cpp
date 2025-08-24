#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, Q; cin >> N >> Q;
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    long long ans = 0;
    for (int i = 0; i < N; i++) ans += min(A[i], B[i]);

    for (int i = 0; i < Q; i++) {
        char c;
        long long X, V; cin >> c >> X >> V;
        X--;

        long long prev = min(A[X], B[X]);
        if (c == 'A') {
            A[X] = V;
        } else {
            B[X] = V;
        }
        long long curr = min(A[X], B[X]);
        ans += (curr - prev);

        cout << ans << endl;
    }


    return 0;
}
