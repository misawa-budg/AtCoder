#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N); for (int i = 0; i < N; ++i) cin >> A[i];
    vector<int> called(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        if (called[i] == 0) called[A[i-1]]++;
    }

    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        if (called[i] == 0) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
