#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;

    vector<int> prime_factors(N + 1, 0);

    for (int i = 2; i <= N; i++) {
        if (prime_factors[i] == 0) {
            for (int j = i; j <= N; j+=i) {
                prime_factors[j]++;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (prime_factors[i] >= K) ans++;
    }

    cout << ans << endl;

    return 0;
}
