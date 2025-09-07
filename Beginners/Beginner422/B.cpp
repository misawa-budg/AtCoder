#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    vector<string> S(H); for (int i = 0; i < H; i++) cin >> S[i];

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') {
                int count = 0;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dy[k], nj = j + dx[k];
                    if (0 <= ni && ni < H && 0 <= nj && nj < W) {
                        if (S[ni][nj] == '#') count++;
                    }
                }
                if (count != 2 && count != 4) {
                    cout << "No" << '\n';
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << '\n';

    return 0;
}
