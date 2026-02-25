#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N, W; cin >> N >> W;
        vector<int> C(N); for (int i = 0; i < N; i++) cin >> C[i];
        
        int period = 2 * W;
        vector<long long> cost(period, 0);
        for (int i = 0; i < N; i++) {
            cost[i % period] += C[i];
        }

        long long base_cost = 0;
        for (int i = 0; i < W; i++) base_cost += cost[i];

        long long ans = base_cost;
        for (int i = 0; i < period; i++) {
            base_cost -= cost[i];
            base_cost += cost[(i + W) % period];
            ans = min(ans, base_cost);
        }
        cout << ans << '\n'; 
    }

    return 0;
}
