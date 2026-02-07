#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, K, X; cin >> N >> K >> X;
    vector<long long> A(N);
    long long total = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        total += A[i];
    }

    sort(A.begin(), A.end(), greater<long long>());

    long long alcohol = 0;
    for (int i = N - K; i < N; i++) {
        alcohol += A[i];
    }
    if (alcohol < X) {
        cout << -1 << '\n';
        return 0;
    }

    long long ans = N - K;
    long long cumulative = 0;
    for (int i = N - K; i < N; i++) {
        cumulative += A[i];
        ans++;
        if (cumulative >= X) {
            break;
        }
    }
    cout << ans << '\n';

    return 0;
}
