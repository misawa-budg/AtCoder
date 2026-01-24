#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    vector<int> cumulative(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cumulative[i] = cumulative[i - 1] + A[i];
    }

    while (Q--) {
        int query; cin >> query;
        if (query == 1) {
            int x; cin >> x;
            cumulative[x] += A[x+1] - A[x];
            swap(A[x], A[x + 1]);
        } else if (query == 2) {
            int l, r; cin >> l >> r;
            cout << cumulative[r] - cumulative[l-1] << "\n";
        }
    }

    return 0;
}
