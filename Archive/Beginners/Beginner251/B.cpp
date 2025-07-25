#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, W; cin >> N >> W;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    set<int> ans;
    for (int i = 0; i < N; i++) {
        if (A[i] <= W) ans.insert(A[i]);
        for (int j = i + 1; j < N; j++) {
            if (A[i] + A[j] <= W) {
                ans.insert(A[i] + A[j]);
            }
            for (int k = j + 1; k < N; k++) {
                if (A[i] + A[j] + A[k] <= W) {
                    ans.insert(A[i] + A[j] + A[k]);
                }
            }
        }
    }
    cout << ans.size() << endl;

    return 0;
}
