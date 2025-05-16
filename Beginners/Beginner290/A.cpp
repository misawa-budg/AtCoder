#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < M; ++i) cin >> B[i];

    int ans = 0;
    for (int i = 0; i < M; i++) {
        ans += A[B[i] - 1];
    }
    cout << ans << endl;

    return 0;
}
