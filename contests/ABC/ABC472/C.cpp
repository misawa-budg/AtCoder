#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M, K; cin >> N >> M >> K;
    vector<long long> A(N); for (int i = 0; i < N; i++) cin >> A[i];
    vector<long long> ate(N, 0);

    long long sum = 0;

    for (int i = 0; i < N; i++) {
        if (i >= M) sum -= ate[i - M];

        if (sum + A[i] <= K) {
            cout << "Yes\n";
            ate[i] = A[i];
            sum += A[i];
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
