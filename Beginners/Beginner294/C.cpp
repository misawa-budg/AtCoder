#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];

    vector<int> C(N + M);
    for (int i = 0; i < N; i++) C[i] = A[i];
    for (int i = 0; i < M; i++) C[N + i] = B[i];
    sort(C.begin(), C.end());

    map<int, int> positions;
    for (int i = 0; i < N + M; i++) {
        positions[C[i]] = i + 1;
    }

    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << positions[A[i]];
    } cout << endl;
    for (int i = 0; i < M; i++) {
        if (i) cout << " ";
        cout << positions[B[i]];
    } cout << endl;


    return 0;
}
