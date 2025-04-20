#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, D; cin >> M >> D;
    int y, m, d; cin >> y >> m >> d;

    if (d == D) {
        d = 1;
        m++;
    } else {
        d++;
    }

    if (m == M + 1) {
        m = 1;
        y++;
    }

    cout << y << " " << m << " " << d << "\n";

    return 0;
}
