#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;
    vector<int> A(N);
    vector<int> ans;
    for (int i = 0; i < N; i++) cin >> A[i];

    for (int i = 0; i < N; i++) {
        if (A[i] % K == 0) {
            ans.push_back(A[i]);
        }
    }

    for (const auto& x : ans) {
        cout << x / K << " ";
    }
    cout << endl;

    return 0;
}
