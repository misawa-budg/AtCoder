#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> P(N);
    for (int i = 1; i < N; ++i) {
        cin >> P[i];
    }

    int cur = N - 1, ans = 0;
    while (cur != 0) {
        cur = P[cur] - 1;
        ans++;
    }
    cout << ans << '\n';


    return 0;
}
