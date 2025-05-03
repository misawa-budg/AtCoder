#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<vector<bool>> isCovered(100, vector<bool>(100, false));
    for (int i = 0; i < N; i++) {
        int fromX, toX, fromY, toY;
        cin >> fromX >> toX >> fromY >> toY;
        for (int x = fromX; x < toX; x++) {
            for (int y = fromY; y < toY; y++) {
                isCovered[y][x] = true;
            }
        }
    }
    int count = 0;
    for (int y = 0; y < 100; y++) {
        for (int x = 0; x < 100; x++) {
            if (isCovered[y][x]) count++;
        }
    }
    cout << count << '\n';

    return 0;
}
