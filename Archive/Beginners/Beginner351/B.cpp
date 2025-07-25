#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<char>> grid(N, vector<char>(N));
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> grid[i][j];

    int ansI = 0, ansJ = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char input;
            cin >> input;
            if (grid[i][j] != input) {
                ansI = i + 1;
                ansJ = j + 1;
            }
        }
    }

    cout << ansI << " " << ansJ << "\n";

    return 0;
}
