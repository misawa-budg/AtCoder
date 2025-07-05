#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q; cin >> Q;
    queue<pair<long long, long long>> q;
    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            long long c, x; cin >> c >> x;
            q.push({x, c});
        } else {
            long long k; cin >> k;
            long long ans = 0;
            while (true) {
                auto [num, count] = q.front();
                if (k - count <= 0) {
                    ans += num * k;
                    cout << ans << '\n';
                    q.front().second -= k;
                    break;
                } else {
                    ans += num * count;
                    k -= count;
                    q.pop();
                }
            }
        }
    }

    return 0;
}
