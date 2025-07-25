#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<vector<int>> A(N), B(N);
    for (int i = 0; i < N; i++) {
        A[i].resize(N);
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        B[i].resize(N);
        for (int j = 0; j < N; j++) {
            cin >> B[i][j];
        }
    }

    vector<vector<int>> C = A;
    for (int rotate = 0; rotate < 4; rotate++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                C[i][j] = A[N - j - 1][i];
            }
        }

        A = C;

        bool ok = true;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (C[i][j] == 1 && C[i][j] != B[i][j]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }
        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

        return 0;
}