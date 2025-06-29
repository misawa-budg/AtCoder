#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X; cin >> N >> X;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    sort(A.begin(), A.end());

    for (int i = 0; i < N; i++) {
        int index = lower_bound(A.begin(), A.end(), A[i] - X) - A.begin();
        if (A[index] == A[i] - X) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}
