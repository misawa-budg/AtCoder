#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N; cin >> N;
    vector<long long> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    if (ranges::count(A, A[0]) == N) {
        cout << "Yes\n";
        return;
    }

    int pos = ranges::count(A, A[0]), neg = ranges::count(A, -A[0]);
    if (pos + neg == N && abs(pos - neg) <= 1) {
        cout << "Yes\n";
        return;
    }

    sort(A.begin(), A.end(), [](long long a, long long b) {
        return abs(a) < abs(b);
    });
    // A[1]/A[0] == A[i]/A[i-1]
    // A[1] * A[1] == A[0] * A[2]
    bool ok = true;
    for (int i = 2; i < N; i++) {
        if (A[i - 2] * A[i] != A[i - 1] * A[i - 1]) {
            ok = false;
            break;
        }
    }
    if (ok) cout << "Yes\n";
    else cout << "No\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
