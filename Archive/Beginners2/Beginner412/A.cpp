#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (B[i] > A[i]) ans++;
    }

    cout << ans << '\n';
    return 0;
}
