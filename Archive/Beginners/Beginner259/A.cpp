#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, X, T, D; cin >> N >> M >> X >> T >> D;

    for (int year = N; year >= M; year--) {
        if (year >= X) continue;
        T -= D;
    }

    cout << T << endl;

    return 0;
}
