#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, P, Q, R, S; cin >> N >> P >> Q >> R >> S;
    vector<int> A(N); for (int i = 0; i < N; ++i) cin >> A[i];
    P--; Q--; R--; S--;
    vector<int> B(N);

    for (int i = 0; i < N; ++i) {
        if (i < P) B[i] = A[i];
        else if (i >= P && i <= Q) B[i] = A[i + (R - P)];
        else if (i > Q && i < R) B[i] = A[i];
        else if (i >= R && i <= S) B[i] = A[i + (P - R)];
        else B[i] = A[i];
    }

    for (int i = 0; i < N; i++) {
        if (i == N - 1) cout << B[i];
        else cout << B[i] << " ";
    }
    cout << endl;

    return 0;
}
