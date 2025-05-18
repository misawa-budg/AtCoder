#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> S(N); for (int i = 0; i < N; i++) cin >> S[i];
    vector<int> ans(N);

    ans[0] = S[0];
    for (int i = 1; i < N; i++) {
        ans[i] = S[i] - S[i - 1];
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i];
        if (i != N - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
