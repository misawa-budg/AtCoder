#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N+1); for (int i = 1; i <= N; i++) cin >> A[i];

    vector<int> prefixSum(N+1, 0);
    for (int i = 0; i < N; i++) {
        prefixSum[i+1] = prefixSum[i] + A[i+1];
    }
    // prefixSum[r] - prefixSum[l-1] == sum(l..r)

    int ans = 0;
    for (int l = 1; l <= N; l++) {
        for (int r = l; r <= N; r++) {
            int sectionSum = prefixSum[r] - prefixSum[l-1];
            bool ok = true;
            for (int i = l; i <= r; i++) {
                if (sectionSum % A[i] == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}
