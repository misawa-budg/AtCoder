#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, Q; cin >> N >> Q;
    vector<int> A(N);
    iota(A.begin(), A.end(), 1);

    long long offset = 0;
    for (int i = 0; i < Q; i++) {
        int query; cin >> query;
        if (query == 1) {
            int p, x; cin >> p >> x;
            p--;
            A[(p + offset) % N] = x;
        } else if (query == 2) {
            int p; cin >> p; p--;
            cout << A[(p + offset) % N] << '\n';
        } else {
            long long k; cin >> k;
            offset = (offset + k) % N;
        }
    }

    return 0;
}
