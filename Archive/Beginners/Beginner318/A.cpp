#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, P; cin >> N >> M >> P;
    int ans = 0;
    while (M + P * ans <= N) {
        ans++;
    }
    cout << ans << endl;

    // cout << (N - M) / P + 1 << endl;

    return 0;
}
