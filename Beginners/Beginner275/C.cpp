#include <bits/stdc++.h>
using namespace std;

const int HEIGHT = 9;
const int WIDTH = 9;

bool valid(int x, int y, const vector<string>& S)
{
    return clamp(x, 0, HEIGHT-1) == x && clamp(y, 0, WIDTH-1) == y && S[x][y] == '#';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> S(9); for (int i = 0; i < 9; ++i) cin >> S[i];

    set<set<pair<int, int>>> ans;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            for (int dx = -8; dx < 9; dx++) {
                for (int dy = -8; dy < 9; dy++) {
                    if (!dx && !dy) continue;
                    int i2 = i + dx, j2 = j + dy;
                    int i3 = i2 - dy, j3 = j2 + dx;
                    int i4 = i3 - dx, j4 = j3 - dy;
                    if (valid(i, j, S) && valid(i2, j2, S) && valid(i3, j3, S) && valid(i4, j4, S)) {
                        set<pair<int, int>> tmp;
                        tmp.insert({i, j});
                        tmp.insert({i2, j2});
                        tmp.insert({i3, j3});
                        tmp.insert({i4, j4});
                        ans.insert(tmp);
                    }
                }
            }
        }
    }

    cout << ans.size() << endl;

    return 0;
}
