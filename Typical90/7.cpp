#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    int Q; cin >> Q;
    vector<int> B(Q); for (int i = 0; i < Q; i++) cin >> B[i];

    for (int i = 0; i < Q; i++) {
        int rate = B[i];

        int index = lower_bound(A.begin(), A.end(), rate) - A.begin();
        int ans = INT_MAX;
        if (index < N)
            ans = min(ans, abs(A[index] - rate));
        if (index > 0)
            ans = min(ans, abs(A[index - 1] - rate));


        cout << ans << endl;
    }

    return 0;
}
