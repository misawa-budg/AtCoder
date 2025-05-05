#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<string> S(N); for (int i = 0; i < N; ++i) cin >> S[i];

    for (int i = 0; i < N - 9 + 1; i++) {
        for (int j = 0; j < M - 9 + 1; j++) {

            bool ok = true;
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    if (S[i + k][j + l] != '#' || S[i+8 - k][j+8 -l] != '#') {
                        ok = false;
                    }
                }
            }

            for (int k = 0; k < 4; k++) {
                if (S[i + 3][j + k] != '.' || S[i + k][j + 3] != '.') {
                    ok = false;
                }
            }

            if (ok) {
                cout << i + 1 << ' ' << j + 1 << '\n';
            }
        }
    }

    return 0;
}
