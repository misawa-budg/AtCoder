#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<int> T(Q);
    for (auto &x : T) cin >> x;
    vector<int> counter(N, 0);

    for (auto &x : T) {
        counter[x - 1]++;
    }

    int ans = 0;
    for (auto &x : counter) {
        if (x % 2 == 0) ans++;
    }

    cout << ans << endl;


    return 0;
}
