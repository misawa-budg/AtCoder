#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q; cin >> H >> W >> Q;
    long long current_H = H;
    long long current_W = W;

    for (int i = 0; i < Q; ++i) {
        int type;
        long long x;
        cin >> type >> x;

        if (type == 1) {
            long long eaten_blocks = x * current_W;
            cout << eaten_blocks << "\n";
            current_H -= x;
        } else if (type == 2) {
            long long eaten_blocks = current_H * x;
            cout << eaten_blocks << "\n";
            current_W -= x;
        }
    }

    return 0;
}
