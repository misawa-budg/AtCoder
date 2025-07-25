#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    vector<string> A(H); for (int i = 0; i < H; ++i) cin >> A[i];
    vector<string> B(H); for (int i = 0; i < H; ++i) cin >> B[i];
    vector<string> temp = A;

    for (int s = 0; s < H; s++) {
        for (int t = 0; t < W; t++) {

            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    temp[i][j] = A[(i - s + H) % H][(j - t + W) % W];
                }
            }

            bool ok = true;
            for (int i = 0; i < H; i++) {
                if (temp[i] != B[i]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
