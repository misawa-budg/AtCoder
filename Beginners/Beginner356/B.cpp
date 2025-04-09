#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    for (int i = 0; i < M; ++i) cin >> A[i];
    vector<vector<int>> meals(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> meals[i][j];
        }
    }

    vector<int> sum(M, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            sum[j] += meals[i][j];
        }
    }

    bool isAccomplished = true;
    for (int i = 0; i < M; i++) {
        if (sum[i] < A[i]) {
            isAccomplished = false;
            break;
        }
    }

    if (isAccomplished) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
