#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, L, Q;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    cin >> M;
    vector<int> B(M);
    for (int i = 0; i < M; i++) cin >> B[i];
    cin >> L;
    vector<int> C(L);
    for (int i = 0; i < L; i++) cin >> C[i];
    cin >> Q;
    vector<int> X(Q);
    for (int i = 0; i < Q; i++) cin >> X[i];

    set<long long> ABCSum;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < L; k++) {
                ABCSum.insert(A[i] + B[j] + C[k]);
            }
        }
    }

    for (int i = 0; i < Q; i++) {
        if (ABCSum.find(X[i]) != ABCSum.end()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
