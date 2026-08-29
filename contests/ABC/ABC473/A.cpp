#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int ans = 0;
    for (int i = N / 2; i < N; i++) ans += A[i];

    cout << ans << '\n';

    return 0;
}
