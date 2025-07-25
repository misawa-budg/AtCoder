#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());

    long long count = 0, ans = 0;
    int r = N;
    for (int i = 0; i < N; i++) {
        r = max(r, i + 1);
        while (r - 1 > i && A[r - 1] + A[i] >= 100000000) {
            r--;
        }
        count += N - r;
    }
    for (int i = 0; i < N; i++) {
        ans += (long long)A[i] * (N - 1);
    }
    ans -= count * 100000000;

    cout << ans << endl;

    return 0;
}
