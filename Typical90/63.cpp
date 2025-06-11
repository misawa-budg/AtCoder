#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    vector<vector<int>> grid(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    for (int bit = 1; bit < (1 << H); bit++) {
        vector<int> row;
        for (int i = 0; i < W; i++) {
            int index = -1; bool flag = false;
            for (int j = 0; j < H; j++) {
                if (bit & (1 << j)) {
                    if (index == -1) {
                        index = grid[j][i];
                    } else if (index != grid[j][i]) {
                        flag = true;
                        break;
                    }
                }
            }
            if (!flag) {
                row.push_back(index);
            }
        }

        int cntH = __builtin_popcount(bit);
        int cntW = 0;
        map<int, int> freq;
        for (int val : row) {
            freq[val]++;
            cntW = max(cntW, freq[val]);
        }
        ans = max(ans, cntH * cntW);
    }

    cout << ans << endl;

    return 0;
}
