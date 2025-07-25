#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < M; ++i) cin >> B[i];

    for (int i = 0; i < M; i++) {
        A.push_back(B[i] + 1);
    }

    sort(A.begin(), A.end());

    cout << A[M - 1] << endl;

    return 0;
}
