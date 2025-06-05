#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    int shift = 0;
    while (Q--) {
        int t, x, y; cin >> t >> x >> y; x--; y--;
        if (t == 1) {
            swap(A[(x + shift) % N], A[(y + shift) % N]);
        } else if (t == 2) {
            shift--;
            shift = (shift + N) % N;
        } else {
            cout << A[(x + shift) % N] << endl;
        }
    }

    return 0;
}
