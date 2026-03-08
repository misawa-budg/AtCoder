#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> C(M); for (int i = 0; i < M; i++) cin >> C[i];
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int A, B; cin >> A >> B; A--;
        if (C[A] < B) {
            ans += C[A];
            C[A] = 0;
        } else {
            ans += B;
            C[A] -= B;
        }
    }
    cout << ans << '\n';

    return 0;
}
