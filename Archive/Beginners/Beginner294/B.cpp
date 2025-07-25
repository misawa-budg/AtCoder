#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    char letter;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] == 0) {
                letter = '.';
            } else {
                letter = 'A' + A[i][j] - 1;
            }
            cout << letter;
        }
        cout << endl;
    }

    return 0;
}
