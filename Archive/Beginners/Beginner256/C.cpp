#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h1, h2, h3, w1, w2, w3;
    cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;

    if (h1 + h2 + h3 != w1 + w2 + w3) {
        cout << 0 << endl;
        return 0;
    }

    // a ~ c, d ~ f, g ~ i
    int ans = 0;
    for (int a = 1; a <= 28; a++) {
        for (int b = 1; b <= 28; b++) {
            for (int d = 1; d <= 28; d++) {
                for (int e = 1; e <= 28; e++) {
                    int c = h1 - a - b;
                    int f = h2 - d - e;
                    int g = w1 - a - d;
                    int h = w2 - b - e;
                    int i = w3 - c - f;

                    if (c > 0 && f > 0 && g > 0 && h > 0 && i > 0) ans++;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
