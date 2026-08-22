#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int total = 0;
    vector<int> L(N); for (int i = 0; i < N; i++) {
        cin >> L[i];
        total += L[i];
    }

    int ans = INT_MAX;
    int left = 0;
    for (int i = 0; i < N; i++) {
        left += L[i];
        ans = min(ans, abs(total - left - left));
    }

    cout << ans << '\n';

    return 0;
}
