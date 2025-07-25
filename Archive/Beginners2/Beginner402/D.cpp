#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> A(M), B(M);
    for (int i = 0; i < M; i++) cin >> A[i] >> B[i];

    vector<int> cnt(N + 1, 0);
    for (int i = 0; i < M; i++) {
        cnt[(A[i] + B[i]) % N]++;
    }

    long long ans = 1LL * M * (M - 1) / 2;
    for (int i = 0; i < N; i++) {
        ans -= 1LL * cnt[i] * (cnt[i] - 1) / 2;
    }
    cout << ans << endl;

    return 0;
}
