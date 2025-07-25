#include <bits/stdc++.h>
using namespace std;

bool paste(vector<string>& board,
           const vector<string>& pat,
           int dy, int dx)
{
    const int H = board.size(), W = board[0].size();
    for (int y = 0; y < (int)pat.size(); ++y)
        for (int x = 0; x < (int)pat[0].size(); ++x)
            if (pat[y][x] == '#') {
                int ny = y + dy, nx = x + dx;
                if (ny < 0 || ny >= H || nx < 0 || nx >= W)
                    return false;
                board[ny][nx] = '#';
            }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int AH, AW; cin >> AH >> AW;
    vector<string> A(AH); for (auto& row : A) cin >> row;
    int BH, BW; cin >> BH >> BW;
    vector<string> B(BH); for (auto& row : B) cin >> row;
    int XH, XW; cin >> XH >> XW;
    vector<string> X(XH); for (auto& row : X) cin >> row;

    const int SHIFT_MIN = -9, SHIFT_MAX = 9;
    for (int dyA = SHIFT_MIN; dyA <= SHIFT_MAX; ++dyA)
        for (int dxA = SHIFT_MIN; dxA <= SHIFT_MAX; ++dxA)
            for (int dyB = SHIFT_MIN; dyB <= SHIFT_MAX; ++dyB)
                for (int dxB = SHIFT_MIN; dxB <= SHIFT_MAX; ++dxB) {

                    vector<string> board(XH, string(XW, '.'));

                    if (!paste(board, A, dyA, dxA)) continue;
                    if (!paste(board, B, dyB, dxB)) continue;

                    bool same = true;
                    for (int y = 0; y < XH && same; ++y)
                        for (int x = 0; x < XW; ++x)
                            if (board[y][x] != X[y][x]) {
                                same = false;
                                break;
                            }

                    if (same) {
                        cout << "Yes\n";
                        return 0;
                    }
                }

    cout << "No\n";
    return 0;
}
