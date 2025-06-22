#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;
    vector<int> A(N), B(K);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < K; ++i) cin >> B[i];

    int maxA = *max_element(A.begin(), A.end());
    for (int i = 0; i < K; i++) {
        if (A[B[i] - 1] == maxA) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}
