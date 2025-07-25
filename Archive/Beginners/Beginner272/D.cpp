#include <bits/stdc++.h>
using namespace std;

long long calculateDistance(int x1, int y1, int x2, int y2)
{
    long long dx = x1 - x2, dy = y1 - y2;
    return dx * dx + dy * dy;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;

    vector<int> sq(M + 1, -1);
    for (int r = 0; r * r <= M; r++) {
        sq[r * r] = r;
    }

    set<pair<int, int>> points;
    int lim = int(sqrt(M));
    for (int dx = -lim; dx <= lim; dx++) {
        long long dy2 = M - dx * dx;
        if (dy2 < 0 || sq[dy2] == -1) continue;
        int dy = sq[dy2];
        for (int sx : {-1, 1}) for (int sy : {-1, 1}) {
            points.insert({dx * sx, dy * sy});
        }
    }

    vector<vector<int>> dist(N, vector<int>(N, INT_MAX));
    queue<pair<int, int>> q;
    auto inside = [&](int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < N;
    };

    dist[0][0] = 0; q.emplace(0, 0);
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (const auto& [dx, dy] : points) {
            int nx = x + dx, ny = y + dy;
            if (inside(nx, ny) && dist[nx][ny] > dist[x][y] + 1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.emplace(nx, ny);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dist[i][j] == INT_MAX) {
                cout << -1 << ' ';
            } else {
                cout << dist[i][j] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
