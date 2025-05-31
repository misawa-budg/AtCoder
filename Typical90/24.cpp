#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += abs(B[i] - A[i]);
    }

    if (ans <= K && (K - ans) % 2 == 0) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
