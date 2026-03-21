#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    long long K; cin >> K;
    vector<long long> A(N); 
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] %= K;
    }

    sort(A.begin(), A.end());

    long long ans = A[N - 1] - A[0]; // 最初
    for (int i = 0; i < N - 1; i++) {
        ans = min(ans, A[i] + K - A[i + 1]);
    }

    cout << ans << '\n';

    return 0;
}
