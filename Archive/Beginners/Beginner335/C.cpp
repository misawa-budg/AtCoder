#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;
    deque<pair<int, int>> dragon;
    for (int i = 0; i < N; i++) dragon.push_back({0, i+1});

    for (int i = 0; i < Q; i++) {
        int query; cin >> query;

        if (query == 1) {
            char direction; cin >> direction;
            auto [y, x] = dragon.front();
            if (direction == 'R') dragon.push_front({y, x + 1});
            else if (direction == 'L') dragon.push_front({y, x - 1});
            else if (direction == 'U') dragon.push_front({y + 1, x});
            else if (direction == 'D') dragon.push_front({y - 1, x});
        } else {
            int part; cin >> part; part--;
            cout << dragon[part].second << " " << dragon[part].first << endl;
        }
    }

    return 0;
}
