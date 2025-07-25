#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long K; cin >> K;
    vector<long long> ans;

    int count = 0;
    for (int bit = 2; bit < (1 << 10); bit++) {
        long long sum = 0;
        for (int i = 9; i >= 0; i--) {
            if (bit & (1 << i)) {
                sum *= 10;
                sum += i;
            }
        }
        ans.push_back(sum);
    }
    sort(ans.begin(), ans.end());
    cout << ans[K - 1] << endl;

    return 0;
}
