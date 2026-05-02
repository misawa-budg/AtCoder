#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> dice(3, vector<int>(6));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> dice[i][j];
        }
    }

    int valid = 0, total = 216;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 6; k++) {
                vector<int> rolls = {dice[0][i], dice[1][j], dice[2][k]};
                sort(rolls.begin(), rolls.end());
                
                if (rolls[0] == 4 && rolls[1] == 5 && rolls[2] == 6) {
                    valid++;
                }
            }
        }
    }

    cout << fixed << setprecision(10) << (double) valid / total << '\n';

    return 0;
}
