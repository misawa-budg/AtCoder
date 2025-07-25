#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X, Y; cin >> X >> Y;
    int all = 36;
    int count = 0;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i + j >= X || abs(i - j) >= Y) count++;
        }
    }

    cout << fixed << setprecision(12) << static_cast<double>(count) / all << endl;

    return 0;
}
