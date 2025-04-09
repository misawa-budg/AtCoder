#include <bits/stdc++.h>
using namespace std;

bool bingo_check(vector<vector<int>> &bingo, int N, int i, int j)
{
    bool isBingo;
    if (i == j) {
        isBingo = true;
        for (int k = 0; k < N; k++) {
            if (!bingo[k][k]) {
                isBingo = false;
                break;
            }
        }
        if (isBingo) return true;
    }

    if (i == N - 1 - j) {
        isBingo = true;
        for (int k = 0; k < N; k++) {
            if (!bingo[k][N - 1 - k]) {
                isBingo = false;
                break;
            }
        }
        if (isBingo) return true;
    }

    isBingo = true;
    for (int k = 0; k < N; k++) {
        if (!bingo[k][j]) {
            isBingo = false;
            break;
        }
    }
    if (isBingo) return true;

    isBingo = true;
    for (int k = 0; k < N; k++) {
        if (!bingo[i][k]) {
            isBingo = false;
            break;
        }
    }
    if(isBingo) return true;

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T;
    cin >> N >> T;

    vector<int> numbers(T);
    for (int i = 0; i < T; i++) cin >> numbers[i];

    vector<vector<int>> bingo(N, vector<int>(N));
    vector<vector<int>> isSelected(N, vector<int>(N, 0));

    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) bingo[i-1][j-1] = N * (i-1) + j;

    for (int i = 0; i < T; i++) {
        int number = numbers[i];
        int y = (number - 1) / N;
        int x = (number - 1) % N;

        isSelected[y][x] = 1;

        if(bingo_check(isSelected, N, y, x)) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
