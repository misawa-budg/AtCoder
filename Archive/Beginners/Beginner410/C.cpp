#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;
    vector<int> A(N);
    iota(A.begin(), A.end(), 1);
    long long head = 0;

    while (Q--) {
        int type; cin >> type;
        if (type == 1) {
            int p, x; cin >> p >> x;
            int idx = (head + p - 1) % N;
            A[idx] = x;
        } else if (type == 2) {
            int p; cin >> p;
            int idx = (head + p - 1) % N;
            cout << A[idx] << '\n';
        } else {
            long long k; cin >> k;
            head = (head + k) % N;
        }
    }

    return 0;
}
