#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X, Y, L, R, A, B; cin >> X >> Y >> L >> R >> A >> B;

    int xhours = 0, yhours = 0;
    for (int i = A; i < B; i++) {
        if (L <= i && i < R) xhours++;
        else yhours++;
    }

    cout << xhours * X + yhours * Y << '\n';

    return 0;
}
