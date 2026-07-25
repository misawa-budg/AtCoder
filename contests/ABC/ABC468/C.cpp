#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> P(N), Q(N);
    for (int i = 0; i < N; i++) cin >> P[i];
    for (int i = 0; i < N; i++) cin >> Q[i];

    vector<int> A(N);
    iota(A.begin(), A.end(), 1);
    int ans = 0;

    do {
        if (P < A && A < Q) ans++;
    } while (next_permutation(A.begin(), A.end()));

    cout << ans << '\n';

    return 0;
}
