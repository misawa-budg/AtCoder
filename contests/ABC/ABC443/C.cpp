#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    long long T; cin >> T;
    vector<long long> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    long long count = T;
    long long prev = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] >= prev) {
            count -= min(1LL * 100, T - A[i]);
            prev = A[i] + 100;
        }
    }
    cout << count << "\n";

    return 0;
}
