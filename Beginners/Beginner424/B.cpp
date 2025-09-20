#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K; cin >> N >> M >> K;
    vector<int> remain(N, M);
    vector<set<int>> solved(N);
    vector<int> ans;
    for (int i = 0; i < K; i++) {
        int A, B; cin >> A >> B; A--;
        if (solved[A].count(B) == 0) {
            solved[A].insert(B);
            remain[A]--;
        }
        if (remain[A] <= 0) {
            ans.push_back(A + 1);
        }
    }

    for (int i = 0; i < (int)ans.size(); i++) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << "\n";

    return 0;
}
