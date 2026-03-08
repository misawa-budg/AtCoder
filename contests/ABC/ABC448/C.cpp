#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> ordA(N);
    iota(ordA.begin(), ordA.end(), 0);
    sort(ordA.begin(), ordA.end(), [&](int x, int y) { return A[x] < A[y]; });

    while (Q--) {
        int K; cin >> K;
        vector<int> B(K); for (int i = 0; i < K; i++) cin >> B[i];

        for (int i = 0; i <= K; i++) {
            bool found = true;
            for (int j = 0; j < K; j++) {
                if (ordA[i] == B[j]-1) {
                    found = false;
                    break;
                }
            }
            if (found) {
                cout << A[ordA[i]] << '\n';
                break;
            }
        }
    }

    return 0;
}
