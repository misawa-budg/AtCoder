#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int H, W; cin >> H >> W;
        vector<string> S(H); for (int i = 0; i < H; i++) cin >> S[i];

        // +1と-1で相殺
        vector<vector<int>> A(H, vector<int>(W, 0));
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (S[i][j] == '#') {
                    A[i][j] = 1;
                } else A[i][j] = -1;
            }
        }

        // 9テストケースでTLE
        // 縦横の長さを入れ替えてみる
        // -> 2つのテストケースでTLEに改善
        if (H > W) {
            vector<vector<int>> A_T(W, vector<int>(H));
            for (int i = 0; i < H; ++i) {
                for (int j = 0; j < W; ++j) {
                    A_T[j][i] = A[i][j];
                }
            }
            A = A_T;
            swap(H, W);
        }

        long long ans = 0;
        vector<int> cumulative(W);
        // TLE2ケースのためfor文の外に宣言を移動
        unordered_map<int, int> count;
        count.reserve(W * 2);
        vector<int> keys; keys.reserve(W + 1);

        //累積和とカウント
        for (int up = 0; up < H; up++) {
            cumulative.assign(W, 0);
            for (int down = up; down < H; down++) {
                for (int j = 0; j < W; j++) cumulative[j] += A[down][j];

                // 累積和が等しい->その間の累積和が0
                // 累積和が正しいものがすでに2つ->ans += 2(区間2つ追加)
                count[0] = 1;
                int cur = 0;
                for (int j = 0; j < W; j++) {
                    cur += cumulative[j];
                    auto &c = count[cur];
                    ans += c;
                    if (c == 0) keys.push_back(cur);
                    c++;
                }

                for (auto k : keys) count[k] = 0;
                keys.clear();
            }
        }
        cout << ans << endl;
    }

    return 0;
}
