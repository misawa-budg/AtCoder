#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L, R; cin >> N >> L >> R;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        if (x <= L && R <= y) ans++;
    }
    cout << ans << endl;

    return 0;
}
