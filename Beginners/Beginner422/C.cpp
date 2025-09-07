#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        long long a, b, c; cin >> a >> b >> c;

        // a, c, [abc]の組み合わせ
        // t <= a, c, (a-t)+b+(c-t)
        // t <= min(a, c, (a+b+c)/3)
        long long ans = min({a, c, (a + b + c) / 3});
        cout << ans << '\n';
    }

    return 0;
}
