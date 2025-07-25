#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K, Q; cin >> N >> K >> Q;
    vector<int> A(K); for (int i = 0; i < K; i++) {
        int input; cin >> input;
        A[i] = input - 1;
    }
    vector<int> L(Q); for (int i = 0; i < Q; i++) cin >> L[i];

    for (int i = 0; i < Q; i++) {
        if (A[L[i] - 1] == N - 1) continue;
        int next = A[L[i] - 1] + 1;
        bool found = false;
        for (int j = 0; j < K; j++) {
            if (A[j] == next) {
                found = true;
                break;
            }
        }
        if (!found) {
            A[L[i] - 1] = next;
        }
    }

    for (int i = 0; i < K; i++) {
        cout << A[i] + 1;
        if (i < K - 1) cout << " ";
    }
    cout << "\n";

    return 0;
}
