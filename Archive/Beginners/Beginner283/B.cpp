#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];
    int Q; cin >> Q;

    for (int i = 0; i < Q; i++) {
        int query, k; cin >> query >> k;
        k--;
        if (query == 1) {
            int x; cin >> x;
            A[k] = x;
        } else {
            cout << A[k] << endl;
        }
    }

    return 0;
}
