#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, T; cin >> N >> M >> T;
    vector<int> A(N); for (int i = 1; i < N; ++i) cin >> A[i];
    vector<int> bonus(N + 1, 0);
    for (int i = 0; i < M; ++i) {
        int x, y; cin >> x >> y;
        bonus[x] = y;
    }

    long long remain = T;
    int i;
    for (i = 1; i < N; i++) {
        if (bonus[i]) {
            remain += bonus[i];
        }
        if (remain - A[i] <= 0) break;
        remain -= A[i];
    }

    if (i == N) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
