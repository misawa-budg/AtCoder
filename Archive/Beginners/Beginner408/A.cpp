#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S; cin >> N >> S;
    vector<int> T(N);
    for (int i = 0; i < N; ++i) {
        cin >> T[i];
    }

    bool ok = true;
    int prev = 0;
    for (int i = 0; i < N; i++) {
        if (T[i] - prev >= S + 1) {
            ok = false;
            break;
        }
        prev = T[i];
    }
    cout << (ok ? "Yes" : "No") << '\n';

    return 0;
}
