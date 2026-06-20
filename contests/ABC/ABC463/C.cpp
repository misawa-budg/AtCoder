#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> H(N), L(N);
    for (int i = 0; i < N; i++) cin >> H[i] >> L[i];

    vector<int> sufMax(N + 1, 0);
    for (int i = N - 1; i >= 0; i--) sufMax[i] = max(H[i], sufMax[i + 1]);

    int Q; cin >> Q;
    while (Q--) {
        int T; cin >> T;

        auto it = upper_bound(L.begin(), L.end(), T);
        int idx = it - L.begin();

        cout << sufMax[idx] << '\n';
    }

    return 0;
}
