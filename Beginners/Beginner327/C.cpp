#include <bits/stdc++.h>
using namespace std;

bool checkVertical(const vector<vector<int>>& grid, int col) {
    set<int> seen;
    for (int i = 0; i < 9; i++) {
        seen.insert(grid[i][col]);
    }
    return seen.size() == 9;
}

bool checkHorizontal(const vector<vector<int>>& grid, int row) {
    set<int> seen;
    for (int j = 0; j < 9; j++) {
        seen.insert(grid[row][j]);
    }
    return seen.size() == 9;
}

bool checkSquare(const vector<vector<int>>& grid, int square) {
    set<int> seen;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            seen.insert(grid[(square / 3) * 3 + i][(square % 3) * 3 + j]);
        }
    }
    return seen.size() == 9;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> grid(9, vector<int>(9));
    for(int i=0;i<9;i++)for(int j=0;j<9;j++)cin>>grid[i][j];

    for (int i = 0; i < 9; i++) {
        if (
            !checkVertical(grid, i) ||
            !checkHorizontal(grid, i) ||
            !checkSquare(grid, i)
        ) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
