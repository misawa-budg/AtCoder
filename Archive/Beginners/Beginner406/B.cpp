#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;
    vector<long long> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    __int128 num = 1;
    __int128 limit = 1;
    for (int i = 0; i < K; i++) {
        limit *= 10;
    }

    for (int i = 0; i < N; i++) {
        num *= A[i];
        if (num >= limit) {
            num = 1;
        }
    }
    cout << (long long)num << endl;

    return 0;
}
