#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];
    int A, B, C, D; cin >> A >> B >> C >> D;
    A--; B--; C--; D--;

    int dy[4] = { -1, 1, 0, 0 };
    int dx[4] = { 0, 0, -1, 1 };

    vector<vector<long long>> dist(H, vector<long long>(W, LLONG_MAX));
    deque<pair<int,int>> deq;
    dist[A][B] = 0;
    deq.emplace_back(A, B);

    while (!deq.empty()) {
        auto [y, x] = deq.front(); deq.pop_front();
        long long cur = dist[y][x];

        for (int k = 0; k < 4; ++k) {
            int ny = y + dy[k], nx = x + dx[k];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            if (S[ny][nx] == '.' && dist[ny][nx] > cur) {
                dist[ny][nx] = cur;
                deq.emplace_front(ny, nx);
            }
        }

        for (int k = 0; k < 4; ++k) {
            for (int step = 1; step <= 2; ++step) {
                int ny = y + dy[k] * step, nx = x + dx[k] * step;
                if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
                if (dist[ny][nx] > cur + 1) {
                    dist[ny][nx] = cur + 1;
                    deq.emplace_back(ny, nx);
                }
            }
        }
    }

    cout << dist[C][D] << '\n';

    return 0;
}
