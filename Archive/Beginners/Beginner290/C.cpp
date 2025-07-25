#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    vector<int> count(K + 1, 0);
    for (int i = 0; i < N; i++) {
        if (A[i] <= K) {
            count[A[i]]++;
        }
    }

    int i;
    for (i = 0; i < K; i++) {
        if (!count[i]) {
            cout << i << endl;
            return 0;
        }
    }
    cout << i << endl;

    return 0;
}
