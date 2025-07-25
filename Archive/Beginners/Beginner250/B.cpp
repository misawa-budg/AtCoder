#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, A, B; cin >> N >> A >> B;
    vector<vector<char>> grid(N * A, vector<char>(N * B));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            for (int k = 0; k < A; k++) {
                for (int l = 0; l < B; l++) {
                    if ((i + j) % 2 == 1) {
                        grid[i * A + k][j * B + l] = '#';
                    } else {
                        grid[i * A + k][j * B + l] = '.';
                    }
                }
            }
        }
    }

    for (int i = 0; i < N * A; i++) {
        for (int j = 0; j < N * B; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}
