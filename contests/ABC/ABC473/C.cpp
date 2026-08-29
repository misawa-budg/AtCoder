#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;
    vector<int> count(K, 0);
    for (int i = 0; i < N; i++) {
        int num; cin >> num; num--;
        count[num]++;
    }

    int max = *max_element(count.begin(), count.end());

    int ans = 0;
    for (int i = 0; i < K; i++) {
        if (count[i] + 1 >= max) ans++;
    }

    cout << ans << '\n';

    return 0;
}
