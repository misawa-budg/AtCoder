#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    vector<int> cnt(N + 1, 0);
    long long ans = 1;

    for (int i = 0; i < N; i++) {
        if (i > 0 && A[i] != A[i - 1]) {
            ans += i - cnt[A[i]];
        }

        cnt[A[i]]++;
    }

    cout << ans << "\n";

    return 0;
}
