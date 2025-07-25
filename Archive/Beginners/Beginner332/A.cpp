#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S, K; cin >> N >> S >> K;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int cost, count; cin >> cost >> count;
        ans += cost * count;
    }

    if (ans < S) ans += K;

    cout << ans << endl;

    return 0;
}
