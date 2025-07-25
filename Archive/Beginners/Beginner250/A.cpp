#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, R, C; cin >> H >> W >> R >> C;
    int adj = 4;
    if (R == 1) adj--;
    if (R == H) adj--;
    if (C == 1) adj--;
    if (C == W) adj--;

    cout << adj << endl;

    return 0;
}
