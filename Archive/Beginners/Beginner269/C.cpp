#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N; cin >> N;

    vector<long long> ans;
    for (long long i = (1LL << 60) - 1; i >= 0; i--) {
        i &= N;
        ans.push_back(i);
    }

    reverse(ans.begin(), ans.end());
    for (auto &x : ans) {
        cout << x << endl;
    }

    return 0;
}
