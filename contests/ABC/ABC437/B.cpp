#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, N; cin >> H >> W >> N;
    vector<vector<int>> count_per_row(H, vector<int>(91, 0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int num; cin >> num;
            count_per_row[i][num]++;
        }
    }

    vector<int> B(N); for (int i = 0; i < N; i++) cin >> B[i];

    int ans = -1;
    for (int i = 0; i < H; i++) {
        int count = 0;
        for (int j = 0; j < N; j++) {
            count += count_per_row[i][B[j]];
        }
        ans = max(ans, count);
    }

    cout << ans << '\n';

    return 0;
}
