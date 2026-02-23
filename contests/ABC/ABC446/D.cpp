#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    unordered_map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int A; cin >> A;
        mp[A] = max(mp[A], mp[A - 1] + 1);
        ans = max(ans, mp[A]);
    }

    cout << ans << '\n';

    return 0;
}
