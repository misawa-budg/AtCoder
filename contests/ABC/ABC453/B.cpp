#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, X; cin >> T >> X;
    vector<int> A(T+1); for (int i = 0; i <= T; i++) cin >> A[i];

    vector<pair<int, int>> ans;
    int saved = A[0];
    ans.emplace_back(0, saved);
    for (int i = 1; i <= T; i++) {
        if (abs(A[i] - saved) >= X) {
            saved = A[i];
            ans.emplace_back(i, saved);
        }
    }
    
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }

    return 0;
}
