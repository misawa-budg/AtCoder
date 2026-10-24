#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    int ans = 0;
    for (int i = 0; i < N - 1; i++) {
        if ((A[i] <= K && K < A[i + 1])
         || (A[i + 1] < K && K <= A[i])) ans++;
    }

    if (A[N - 1] == K) ans++;

    cout << ans << '\n';

    return 0;
}
