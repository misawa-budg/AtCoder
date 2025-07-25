#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    vector<string> S(H); for (int i = 0; i < H; i++) cin >> S[i];

    pair<int, int> start = {-1, -1}, goal = {-1, -1};
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == 'o' && start.first == -1) {
                start = {i, j};
            } else if (S[i][j] == 'o') {
                goal = {i, j};
            }
        }
    }

    cout << abs(start.first - goal.first) + abs(start.second - goal.second) << '\n';

    return 0;
}
