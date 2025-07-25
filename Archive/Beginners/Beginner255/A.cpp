#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C; cin >> R >> C;
    vector<vector<int>> A(2, vector<int>(2));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> A[i][j];
        }
    }

    cout << A[R - 1][C - 1] << '\n';

    return 0;
}
