#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> A(N); for (int i = 0; i < N; ++i) cin >> A[i];

    for (int i = 0; i < N; i++) {
        vector<bool> used(M + 1, false);
        for (int j = 0; j < N - i; j++) {
            used[A[j]] = true;
        }

        bool ok = true;
        for (int j = 1; j <= M; j++) {
            if (!used[j]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << i << endl;
            return 0;
        }
    }
    cout << N << endl;

    return 0;
}
