#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> C(M+1); for (int i = 1; i <= M; i++) cin >> C[i];
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        if (C[A[i]] < B[i]) {
            ans += C[A[i]];
            C[A[i]] = 0;
        } else {
            ans += B[i];
            C[A[i]] -= B[i];
        }
    }
    cout << ans << '\n';

    return 0;
}
