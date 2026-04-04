#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    int M; cin >> M;
    vector<string> S(M);
    bool have[11][11][26];
    for (int i = 0; i < M; i++) {
        cin >> S[i];
        for (int j = 0; j < S[i].length(); j++) {
            have[S[i].length()][j + 1][S[i][j] - 'a'] = true;
        }
    }

    for (int i = 0; i < M; i++) {
        if (S[i].length() != N) {
            cout << "No\n";
            continue;
        }

        bool ok = true;
        for (int j = 0; j < N; j++) {
            int needLen = A[j], needPos = B[j];
            char needChar = S[i][j];

            if (!have[needLen][needPos][needChar - 'a']) {
                ok = false;
                break;
            }
        }
        
        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
