#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X, Y; cin >> N >> X >> Y;

    if (N == 1) {
        cout << 0 << '\n';
        return 0;
    }

    vector<long long> R(N + 1);
    vector<long long> B(N + 1);
    R[1] = 0; B[1] = 1;

    for (int n = 2; n <= N; n++) {
        B[n] = R[n - 1] + Y * B[n - 1];
        R[n] = R[n - 1] + X * B[n];
    }

    cout << R[N] << '\n';

    return 0;
}
