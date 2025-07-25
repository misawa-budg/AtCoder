#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K, G, M; cin >> K >> G >> M;
    int glass = 0, mug = 0;
    for (int i = 0; i < K; i++) {
        if (glass == G) {
            glass = 0;
        } else if (mug == 0) {
            mug = M;
        } else {
            if (G - glass > mug) {
                glass += mug;
                mug = 0;
            } else {
                mug -= G - glass;
                glass = G;
            }
        }
    }

    cout << glass << " " << mug << "\n";

    return 0;
}
