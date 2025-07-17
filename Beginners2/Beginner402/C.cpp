#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<set<int>> meal(M + 1);
    vector<set<int>> ingredient(N + 1);
    for (int i = 1; i <= M; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int x; cin >> x;
            meal[i].insert(x);
            ingredient[x].insert(i);
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int target; cin >> target;
        for (int x : ingredient[target]) {
            if (meal[x].count(target)) {
                meal[x].erase(target);
                if (meal[x].empty()) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }





    return 0;
}
