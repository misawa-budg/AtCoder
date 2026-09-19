#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M; cin >> N >> M;
    long long K, X, Y; cin >> K >> X >> Y;
    vector<long long> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<long long> sumA(N + 1), sumB(M + 1), kdollar(M + 1);

    for (int i = 0; i < N; i++) {
        sumA[i + 1] = sumA[i] + A[i];
    }

    for (int i = 0; i < M; i++) {
        sumB[i + 1] = sumB[i] + B[i];
        kdollar[i + 1] = kdollar[i] + (B[i] + K - 1) / K;
    }

    long long money = X + K * Y;
    int ans = 0;

    for (int i = 0; i <= M; i++) {
        if (kdollar[i] > Y || sumB[i] > money) break;

        int dessert = upper_bound(sumA.begin(), sumA.end(), money - sumB[i]) - sumA.begin() - 1;

        ans = max(ans, i + dessert);
    }

    cout << ans << '\n';

    return 0;
}
