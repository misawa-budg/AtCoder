#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<pair<int, int>> deliciousness (N);
    int maxS = 0, index;
    for (int i = 0; i < N; i++) {
        int f, s; cin >> f >> s;
        deliciousness[i] = {f, s};
        if (s > maxS) {
            maxS = s;
            index = i;
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (i == index) continue;

        int tmp;
        if (deliciousness[i].first == deliciousness[index].first) {
            tmp = maxS + deliciousness[i].second / 2;
        } else {
            tmp = maxS + deliciousness[i].second;
        }
        ans = max(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}
