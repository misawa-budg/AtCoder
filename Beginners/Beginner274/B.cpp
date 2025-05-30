#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    vector<string> grid(H); for (int i = 0; i < H; i++) cin >> grid[i];

    for (int column = 0; column < W; column++) {
        int ans = 0;
        for (int row = 0; row < H; row++) {
            if (grid[row][column] == '#') {
                ans++;
            }
        }
        cout << ans << (column == W - 1 ? '\n' : ' ');
    }

    return 0;
}
