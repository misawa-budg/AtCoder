#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<string> S(N); for (int i = 0; i < N; i++) cin >> S[i];

    int ans = 0;
    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            bool ok = true;
            for (int k = 0; k < M; k++) {
                if (S[i][k] != 'o' && S[j][k] != 'o') {
                    ok = false;
                    break;
                }
            }
            if (ok) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
