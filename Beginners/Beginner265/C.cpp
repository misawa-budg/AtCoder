#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    vector<string> S(H); for (int i = 0; i < H; i++) cin >> S[i];
    vector<vector<char>> visited(H, vector<char>(W, 0));

    int i = 0, j = 0;
    while (true) {
        if (visited[i][j]) {
            cout << -1 << '\n';
            return 0;
        }

        visited[i][j] = 1;
        if (S[i][j] == 'U') {
            if (i == 0) break;
            i--;
        } else if (S[i][j] == 'D') {
            if (i == H - 1) break;
            i++;
        } else if (S[i][j] == 'L') {
            if (j == 0) break;
            j--;
        } else if (S[i][j] == 'R') {
            if (j == W - 1) break;
            j++;
        }
    }

    cout << i + 1 << ' ' << j + 1 << '\n';

    return 0;
}
