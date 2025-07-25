#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<pair<int, int>> ladders(N);
    for (int i = 0; i < N; i++) {
        cin >> ladders[i].first >> ladders[i].second;
    }

    map<int, vector<int>> to;
    for (int i = 0; i < N; i++) {
        int a = ladders[i].first;
        int b = ladders[i].second;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    set<int> visited;
    deque<int> dq;
    int ans = 0;
    dq.push_back(1); visited.insert(1);
    while (!dq.empty()) {
        int current = dq.back(); dq.pop_back();
        ans = max(ans, current);
        for (int next : to[current]) {
            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                dq.push_back(next);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
