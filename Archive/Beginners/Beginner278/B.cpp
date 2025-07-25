#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, M; cin >> H >> M;
    int A, B, C, D;
    int AC, BD;

    while (true) {
        A = H / 10; B = H % 10;
        C = M / 10; D = M % 10;
        AC = A * 10 + C; BD = B * 10 + D;

        if (0 <= AC && AC <= 23 && 0 <= BD && BD <= 59) {
            cout << H << " " << M << endl;
            break;
        }

        M++;
        if (M == 60) {
            M = 0;
            H++;
        }
        if (H == 24) H = 0;
    }

    return 0;
}
