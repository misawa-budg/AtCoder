#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, K; cin >> N >> K;

    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        string number = to_string(i);
        long long sum = 0;
        for (char& c : number) {
            sum += (c - '0');
        }
        if (sum == K) ans++;
    }
    cout << ans << '\n';

    return 0;
}
