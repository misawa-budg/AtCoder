#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> costs(N); for (int i = 0; i < N; i++) cin >> costs[i];
    vector<vector<int>> animal_zoos(M);
    for (int i = 0; i < M; i++) {
        int count; cin >> count;
        for (int j = 0; j < count; j++) {
            int zoo; cin >> zoo; zoo--;
            animal_zoos[i].push_back(zoo);
        }
    }

    long long ans = LLONG_MAX;
    int total = 1;
    for(int i = 0; i < N; i++) total *= 3;

    vector<int> visits(N, 0);
    for(int mask = 0; mask < total; mask++){
        int t = mask;
        for(int i = 0; i < N; i++){
            visits[i] = t % 3;
            t /= 3;
        }

        bool ok = true;
        for(int a = 0; a < M; a++){
            int cnt = 0;
            for(int z : animal_zoos[a]){
                cnt += visits[z];
                if(cnt >= 2) break;
            }
            if(cnt < 2){
                ok = false;
                break;
            }
        }
        if(!ok) continue;

        long long cost = 0;
        for(int i = 0; i < N; i++){
            cost += visits[i] * costs[i];
        }
        ans = min(ans, cost);
    }
    if(ans == LLONG_MAX) cout << -1 << '\n';
    else cout << ans << '\n';

    return 0;
}
