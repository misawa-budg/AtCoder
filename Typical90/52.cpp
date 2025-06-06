#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    long long ans = 1;
    for (int i = 0; i < N; ++i) {
        long long tmp = 0;
        for (int j = 0; j < 6; ++j) {
            long long input; cin >> input;
            tmp += input;
        }
        ans = (ans * (tmp % 1000000007)) % 1000000007;
    }

    cout << ans << endl;

    return 0;
}
