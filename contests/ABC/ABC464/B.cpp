#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    vector<string> C(H);
    for (int i = 0; i < H; i++) cin >> C[i];

    int minr = H, maxr = -1, minc = W, maxc = -1;

    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            if (C[r][c] == '#') {
                minr = min(minr, r);
                maxr = max(maxr, r);
                minc = min(minc, c);
                maxc = max(maxc, c);
            }
        }
    }

    for (int r = minr; r <= maxr; r++) {
        for (int c = minc; c <= maxc; c++) {
            cout << C[r][c];
        }
        cout << endl;
    }

    return 0;
}
