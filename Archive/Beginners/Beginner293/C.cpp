#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    int length = H + W - 2;
    vector<int> direction(length, 0);
    for (int i = 0; i < W - 1; i++) {
        direction[H + i - 1] = 1;
    }

    int ans = 0;
    do {
        int x = 0, y = 0;
        set<int> visited; visited.insert(A[0][0]);
        for (int i = 0; i < length; i++) {
            if (direction[i]) x++;
            else y++;
            visited.insert(A[y][x]);
        }
        if (visited.size() == H + W - 1) ans++;
    } while (next_permutation(direction.begin(), direction.end()));

    cout << ans << endl;

    return 0;
}
