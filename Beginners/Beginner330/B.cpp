#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L, R; cin >> N >> L >> R;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    for (int i = 0; i < N; i++) {
        if (A[i] < L) {
            cout << L << " ";
        } else if (A[i] > R) {
            cout << R << " ";
        } else {
            cout << A[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
