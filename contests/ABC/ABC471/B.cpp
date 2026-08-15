#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    map<string, int> freq;

    for (int i = 0; i < N; i++) {
        string ans; cin >> ans;
        transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
        freq[ans]++;
    }

    int ans = 0;
    for (auto it = freq.begin(); it != freq.end(); it++) ans = max(ans, it->second);

    cout << ans << '\n';

    return 0;
}
