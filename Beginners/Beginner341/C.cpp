#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, N; cin >> H >> W >> N;
    string T; cin >> T;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    long long ans = 0;
    for (int y = 1; y < H - 1; y++) {
        for (int x = 1; x < W - 1; x++) {
            if (S[y][x] == '#') continue;

            // 不時着したマスからチェック開始
            bool ok = true;
            int ny = y, nx = x;
            for (int i = 0; i < N; i++) {
                ny += (T[i] == 'U' ? -1 : T[i] == 'D' ? 1 : 0);
                nx += (T[i] == 'L' ? -1 : T[i] == 'R' ? 1 : 0);

                if (S[ny][nx] == '#') {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
