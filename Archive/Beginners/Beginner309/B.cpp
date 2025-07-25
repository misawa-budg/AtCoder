#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<string> inputs(N); for (int i = 0; i < N; i++) cin >> inputs[i];
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) A[i][j] = inputs[i][j] - '0';
    vector<vector<int>> B(N, vector<int>(N));

    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            B[i][j] = A[i][j];
        }
    }
    for (int i = 1; i < N; i++) {
        B[i - 1][0] = A[i][0];
        B[i][N - 1] = A[i - 1][N - 1];
        B[0][i] = A[0][i - 1];
        B[N - 1][i - 1] = A[N - 1][i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << B[i][j];
        }
        cout << endl;
    }

    return 0;
}
