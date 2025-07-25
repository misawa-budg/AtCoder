#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    vector<string> S(H); for (int i = 0; i < H; i++) cin >> S[i];

    int ans = 0;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            if (S[i][j] == '#') ans++;

    cout << ans << endl;

    return 0;
}
