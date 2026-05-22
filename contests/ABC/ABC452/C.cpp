#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    int M; cin >> M;
    vector<string> S(M);

    bool can_use[11][11][26];
    memset(can_use, false, sizeof(can_use));

    for (int i = 0; i < M; i++) {
        cin >> S[i];
        int len = S[i].length();

        for (int j = 0; j < len; j++) {
            int idx = S[i][j] - 'a';
            can_use[len][j][idx] = true;
        }
    }

    for (int i = 0; i < M; i++) {
        string center = S[i];

        if (center.length() != N) {
            cout << "No\n";
            continue;
        }

        bool possible = true;
        for (int j = 0; j < N; j++) {
            int target_len = A[j];
            int target_pos = B[j] - 1;
            int target_char = center[j] - 'a';

            if (!can_use[target_len][target_pos][target_char]) {
                possible = false;
                break;
            }
        }

        cout << (possible ? "Yes\n" : "No\n");
    }

    return 0;
}
