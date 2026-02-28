#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, N; cin >> H >> W >> N;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }
    set<int> B;
    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        B.insert(num);
    }

    int ans = 0;
    for (int i = 0; i < H; i++) {
        int num = 0;
        for (int j = 0; j < W; j++) {
            if (B.contains(A[i][j])) num++;
        }
        ans = max(ans, num);
    }

    cout << ans << '\n';

    return 0;
}
