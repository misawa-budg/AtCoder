#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    vector<vector<long long>> A(H, vector<long long>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }
    int H2, W2; cin >> H2 >> W2;
    vector<vector<long long>> B(H2, vector<long long>(W2));
    for (int i = 0; i < H2; i++) {
        for (int j = 0; j < W2; j++) {
            cin >> B[i][j];
        }
    }

    for (int cols = 0; cols < (1 << H); cols++) {
        for (int rows = 0; rows < (1 << W); rows++) {
            vector<long long> col, row;
            for (int j = 0; j < H; j++) if (cols & (1 << j)) col.push_back(j);
            for (int i = 0; i < W; i++) if (rows & (1 << i)) row.push_back(i);
            if (row.size() != W2 || col.size() != H2) continue;

            bool match = true;
            for (int i = 0; i < H2; i++) {
                for (int j = 0; j < W2; j++) {
                    if (A[col[i]][row[j]] != B[i][j]) {
                        match = false;
                        break;
                    }
                }
            }
            if (match) {
                cout << "Yes\n";
                return 0;
            }
        }
    }

    cout << "No\n";

    return 0;
}
