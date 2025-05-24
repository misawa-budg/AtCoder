#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    vector<int> columnSum(W, 0), rowSum(H, 0);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            int input;
            cin >> input;
            A[i][j] = input;
            columnSum[j] += input;
            rowSum[i] += input;
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cout << rowSum[i] + columnSum[j] - A[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}
