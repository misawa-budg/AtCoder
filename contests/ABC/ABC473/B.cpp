#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> count(101, 0);

    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        count[num]++;
    }

    int ans = 0;
    for (int i = 1; i <= 100; i++) {
        if (count[i] % 2 == 1) ans += i;
    }

    cout << ans << '\n';

    return 0;
}
