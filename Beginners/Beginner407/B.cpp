#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X, Y; cin >> X >> Y;

    const int all = 36;

    int good = 0;
    for (int first = 1; first <= 6; first++) {
        for (int second = 1; second <= 6; second++) {
            if (first + second >= X || abs(first - second) >= Y) {
                good++;
            }
        }
    }

    cout << fixed << setprecision(15) << static_cast<double>(good) / all << endl;

    return 0;
}
