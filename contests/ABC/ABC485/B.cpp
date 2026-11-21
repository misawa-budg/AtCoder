#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<string> S(N); for (int i = 0; i < N; i++) cin >> S[i];

    
    for (int i = 0; i < N; i++) {
        bool broken = true;
        for (int j = 0; j < M; j++) {
            if (S[i][j] == 'o') {
                broken = false;
                break;
            }
        }

        if (broken) {
            cout << "Faucet " << i + 1 << '\n';
        }
    }

    for (int j = 0; j < M; j++) {
        bool broken = true;
        for (int i = 0; i < N; i++) {
            if (S[i][j] == 'o') {
                broken = false;
                break;
            }
        }

        if (broken) {
            cout << "Drain " << j + 1 << '\n';
        }
    }

    return 0;
}
