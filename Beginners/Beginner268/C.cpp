#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> pos(N);
    for (int i = 0; i < N; i++) {
        cin >> pos[i];
    }

    vector<int> count(N, 0);
    for (int i = 0; i < N; i++) {
        int center = (pos[i] - i + N) % N;
        count[(center - 1 + N) % N]++;
        count[center]++;
        count[(center + 1) % N]++;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, count[i]);
    }
    cout << ans << '\n';

    return 0;
}
