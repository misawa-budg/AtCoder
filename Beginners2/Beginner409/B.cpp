#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());

    for (int i = 0; i < N; i++) {
        if (A[i] >= N - i) {
            cout << N - i << endl;
            return 0;
        }
    }
    cout << 0 << endl;

    return 0;
}
