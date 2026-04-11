#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, X; cin >> T >> X;
    vector<int> A(T + 1); for (int i = 0; i < T + 1; i++) cin >> A[i];

    int saved = A[0];
    cout << 0 << ' ' << A[0] << '\n';
    for (int i = 1; i <= T; i++) {
        if (abs(A[i] - saved) >= X) {
            saved = A[i];
            cout << i << ' ' << A[i] << '\n';
        }
    }

    return 0;
}
