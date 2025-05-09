#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    vector<string> S(H); for (int i = 0; i < H; i++) cin >> S[i];

    int Hmin = H, Hmax = 0;
    int Wmin = W, Wmax = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') {
                Hmin = min(Hmin, i);
                Hmax = max(Hmax, i);
                Wmin = min(Wmin, j);
                Wmax = max(Wmax, j);
            }
        }
    }

    for (int i = Hmin; i <= Hmax; i++) {
        for (int j = Wmin; j <= Wmax; j++) {
            if (S[i][j] == '.') {
                cout << i + 1 << ' ' << j + 1 << endl;
                return 0;
            }
        }
    }

    return 0;
}
