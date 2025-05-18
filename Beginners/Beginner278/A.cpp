#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;
    vector<int> A(N + K, 0); for (int i = 0; i < N; i++) cin >> A[i];

    for (int i = K; i < N + K; i++) {
        cout << A[i];
        if (i != N + K - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
