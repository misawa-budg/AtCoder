#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    vector<string> S(H); for (int i = 0; i < H; i++) cin >> S[i];
    vector<string> T(H); for (int i = 0; i < H; i++) cin >> T[i];

    vector<string> S2(W), T2(W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            S2[j] += S[i][j];
            T2[j] += T[i][j];
        }
    }

    sort(S2.begin(), S2.end());
    sort(T2.begin(), T2.end());

    if (S2 == T2) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}
