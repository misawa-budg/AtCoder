#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());

    int ans = 0;
    // for (int i = 0; i < N; i++) {
    //     int startIndex = A[i];
    //     int endIndex = A[i] + M;
    //     int presentCount = lower_bound(A.begin(), A.end(), endIndex) - lower_bound(A.begin(), A.end(), startIndex);
    //     ans = max(ans, presentCount);
    // }
    int r = 0;
    for (int l = 0; l < N; l++) {
        while (r < N && A[r] < A[l] + M) {
            r++;
        }
        ans = max(ans, r - l);
    }
    cout << ans << endl;

    return 0;
}
