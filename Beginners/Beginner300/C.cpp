#include <bits/stdc++.h>
using namespace std;

int crossSize(int i, int j, const vector<string>& S)
{
    int H = S.size(), W = S[0].size();
    int size = 0;
    for (int k = 1; k <= min(H, W) / 2; k++) {
        if (i - k < 0 || i + k >= H || j - k < 0 || j + k >= W) break;
        if (S[i+k][j+k]=='#'&&S[i-k][j+k]=='#'&&S[i+k][j-k]=='#'&&S[i-k][j-k]=='#') {
            size++;
        } else {
            break;
        }
    }
    return size;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    vector<string> S(H); for (int i = 0; i < H; ++i) cin >> S[i];
    vector<int> counter(min(H, W) + 1, 0);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') {
                int size = crossSize(i, j, S);
                counter[size]++;
            }
        }
    }

    for (int i = 1; i < counter.size(); i++) {
        if (i > 1) cout << " ";
        cout << counter[i];
    }
    cout << endl;

    return 0;
}
