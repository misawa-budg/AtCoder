#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    int ans = 0;

    for (int i = 0; i < N - 2; i++) {
        if (A[i] < A[i + 1] && A[i + 1] > A[i + 2]) ans++;
    }

    cout << ans << '\n';

    return 0;
}
