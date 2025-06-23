#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<string> A(N); for (int i = 0; i < N; i++) cin >> A[i];
    vector<string> ans(N, string(N, ' '));

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            int layer = min({r, c, N - r + 1, N - c + 1});
            int rotations = layer % 4;
            int nr = r, nc = c;
            if (rotations == 1) {
                nr = c;
                nc = N - r + 1;
            } else if (rotations == 2) {
                nr = N - r + 1;
                nc = N - c + 1;
            } else if (rotations == 3) {
                nr = N - c + 1;
                nc = r;
            }
            ans[nr - 1][nc - 1] = A[r - 1][c - 1];
        }
    }

    for (const auto& row : ans) {
        cout << row << '\n';
    }


    return 0;
}
