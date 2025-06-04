#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    unordered_map<int, int> cnt;
    int kinds = 0;
    int ans = 0;

    for (int l = 0, r = 0; r < N; r++) {
        if (++cnt[A[r]] == 1) kinds++;

        while (kinds > K) {
            if (--cnt[A[l]] == 0) kinds--;
            l++;
        }
        ans = max(ans, r - l + 1);
    }

    cout << ans << endl;

    return 0;
}
