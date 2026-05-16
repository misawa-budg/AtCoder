#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int count = 0;

            for (int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];

                if (nx < 0 || H <= nx || ny < 0 || W <= ny) continue;
                count++;
            }
            cout << count << ' ';
        }
        cout << '\n';
    }

    return 0;
}
