#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M; cin >> N >> M;
    vector<long long> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    long long weightSum = 0, simpleSum = 0;
    for (long long i = 1; i <= M; i++) {
        weightSum += i * A[i - 1];
        simpleSum += A[i - 1];
    }

    long long ans = weightSum;

    for (int i = 1; i <= N - M; i++) {
        weightSum = weightSum - simpleSum + (M * A[i + M - 1]);
        simpleSum = simpleSum - A[i - 1] + A[i + M - 1];
        ans = max(ans, weightSum);
    }

    cout << ans << '\n';

    return 0;
}
