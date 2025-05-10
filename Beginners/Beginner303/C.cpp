#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, H, K; cin >> N >> M >> H >> K;
    string S; cin >> S;
    set<pair<int, int>> points;
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        points.insert({x, y});
    }

    pair<int, int> here = {0, 0};
    for (char c : S) {
        switch (c) {
            case 'R': here.first++; break;
            case 'L': here.first--; break;
            case 'U': here.second++; break;
            case 'D': here.second--; break;
        }

        H--;
        if (H < 0) {
            cout << "No" << endl;
            return 0;
        }

        if (points.count(here) && H < K) {
            points.erase(here);
            H = K;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
