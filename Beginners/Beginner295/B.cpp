#include <bits/stdc++.h>
using namespace std;

vector<string> S;

void explode(int y, int x, char power)
{
    int p = power - '0';
    for (int i = -p; i <= p; i++) {
        for (int j = -p; j <= p; j++) {
            if (i == 0 && j == 0) S[y][x] = '.';
            if (abs(i) + abs(j) <= p) {
                int ny = y + i, nx = x + j;
                if (ny < 0 || ny >= S.size() || nx < 0 || nx >= S[0].size()) continue;
                if (S[ny][nx] == '#') S[ny][nx] = '.';
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C; cin >> R >> C;
    for (int i = 0; i < R; i++) {
        string s; cin >> s;
        S.push_back(s);
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if ('1' <= S[i][j] && S[i][j] <= '9') {
                explode(i, j, S[i][j]);
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << S[i][j];
        }
        cout << '\n';
    }

    return 0;
}
