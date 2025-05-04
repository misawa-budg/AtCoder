#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N); for (int i = 0; i < N; ++i) cin >> A[i];

    sort(A.begin(), A.end());
    int prev = A[0];
    for (int i = 1; i < N; i++) {
        if (A[i] - 1 != prev) {
            cout << A[i - 1] + 1 << endl;
            return 0;
        }
        prev = A[i];
    }

    return 0;
}
