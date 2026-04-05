#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    int reached = 0;
    int ans = 0;

    for (int i = 0; i < N; i++) {
        if (reached < i) break;
        reached = max(reached, i + A[i] - 1);
        ans++;
    }

    cout << ans << '\n';

    return 0;
}
