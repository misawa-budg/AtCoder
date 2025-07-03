#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;
    vector<long long> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    __int128 limit = 1;
    for (int i = 0; i < K; i++) {
        limit *= 10;
    }

    __int128 result = 1;
    for (int i = 0; i < N; i++) {
        if (result * A[i] >= limit) result = 1;
        else result *= A[i];
    }
    cout << (long long)result << '\n';

    return 0;
}
