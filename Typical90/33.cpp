#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    if (H == 1 || W == 1) cout << H * W << endl;
    else {
        cout << ((H + 1) / 2) * ((W + 1) / 2) << endl;
    }

    return 0;
}