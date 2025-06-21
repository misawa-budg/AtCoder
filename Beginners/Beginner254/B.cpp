#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<vector<int>> A(N, vector<int>(N, INT_MIN));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                A[i][j] = 1;
            } else {
                A[i][j] = A[i - 1][j - 1] + A[i - 1][j];
            }
        }
    }

    for (auto &vec : A) {
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] != INT_MIN) {
                cout << vec[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
