#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int count = (0<i) + (i<H-1) + (0<j) + (j<W-1);
            cout << count << ' ';
        }
        cout << '\n';
    }

    return 0;
}
