#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N); 
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }

    vector<int> ans(N);
    for (int i = N - 1; i >= 0; i--) {
        if (A[i] == i) ans[i] = i;
        else ans[i] = ans[A[i]];
    }

    for (int i = 0; i < ans.size(); i++) {
        if (i) cout << ' ';
        cout << ans[i] + 1;
    } cout << '\n';

    return 0;
}
