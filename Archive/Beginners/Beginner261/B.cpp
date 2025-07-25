#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<string> S(N); for (int i = 0; i < N; ++i) cin >> S[i];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (S[i][j] == 'W' && S[j][i] != 'L') {
                cout << "incorrect" << '\n';
                return 0;
            }
            if (S[i][j] == 'L' && S[j][i] != 'W') {
                cout << "incorrect" << '\n';
                return 0;
            }
            if (S[i][j] == 'D' && S[j][i] != 'D') {
                cout << "incorrect" << '\n';
                return 0;
            }
        }
    }
    cout << "correct" << '\n';

    return 0;
}
