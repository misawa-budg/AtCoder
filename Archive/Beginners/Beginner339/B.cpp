#include <bits/stdc++.h>
using namespace std;

char turnClockwise(char c)
{
    if (c == 'N') return 'E';
    if (c == 'E') return 'S';
    if (c == 'S') return 'W';
    if (c == 'W') return 'N';
    return c;
}

char turnCounterClockwise(char c)
{
    if (c == 'N') return 'W';
    if (c == 'W') return 'S';
    if (c == 'S') return 'E';
    if (c == 'E') return 'N';
    return c;
}

pair<int, int> stepOne(int &y, int &x, int H, int W, char direction)
{
    if (direction == 'N') {
        if (y > 0) return {y - 1, x};
        else return {H - 1, x};
    } else if (direction == 'E') {
        if (x < W - 1) return {y, x + 1};
        else return {y, 0};
    } else if (direction == 'S') {
        if (y < H - 1) return {y + 1, x};
        else return {0, x};
    } else {
        if (x > 0) return {y, x - 1};
        else return {y, W - 1};
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, N; cin >> H >> W >> N;
    vector<vector<char>> grid(H, vector<char>(W, '.'));

    int y = 0, x = 0;
    char direction = 'N';
    for (int i = 0; i < N; i++) {
        if (grid[y][x] == '.') {
            grid[y][x] = '#';
            direction = turnClockwise(direction);
            auto m = stepOne(y, x, H, W, direction);
            y = m.first; x = m.second;
        } else {
            grid[y][x] = '.';
            direction = turnCounterClockwise(direction);
            auto m = stepOne(y, x, H, W, direction);
            y = m.first; x = m.second;
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}
