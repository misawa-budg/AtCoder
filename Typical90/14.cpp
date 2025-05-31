#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += abs(A[i] - B[i]);
    }
    cout << ans << endl;

    return 0;
}
