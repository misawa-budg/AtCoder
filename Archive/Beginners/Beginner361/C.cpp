#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    sort(A.begin(), A.end());

    int ans = 1e10;
    for (int i = 0; i <= K; i++) {
        ans = min(ans, A[N - K - 1 + i] - A[i]);
    }

    cout << ans << endl;

    return 0;
}
