#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;
    vector<pair<int, int>> balls(N);
    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        balls[i] = make_pair(num, i+1);
    }
    sort(balls.begin(), balls.end(), [&](auto x, auto y){return x.first < y.first;});

    while (Q--) {
        int K; cin >> K;
        vector<int> excludes(K); for (int i = 0; i < K; i++) cin >> excludes[i];

        int idx = 0;
        while (true) {
            bool found = true;
            for (int i = 0; i < K; i++) {
                if (balls[idx].second == excludes[i]) {
                    found = false;
                    break;
                }            
            }
            if (found) {
                cout << balls[idx].first << '\n';
                break;
            }
            idx++;
        }
    }

    return 0;
}
