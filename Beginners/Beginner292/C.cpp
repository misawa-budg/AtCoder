#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<long long> num(N + 1, 0);

    for (int x = 1; x <= N; x++) {
        for (int y = 1; x * y <= N; y++) {
            num[x * y]++;
        }
    }

    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += num[i] * num[N - i];
    }
    cout << ans << endl;

    return 0;
}
