#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<pair<char, long long>> runlengths(N);
    for (int i = 0; i < N; i++) {
        cin >> runlengths[i].first >> runlengths[i].second;
    }

    int length = 0;
    string ans;
    for (const auto& run : runlengths) {
        for (int i = 0; i < run.second && length <= 100; i++) {
            ans += run.first;
            length++;
        }
        if (length > 100) {
            ans = "Too Long";
            break;
        }
    }
    cout << ans << endl;

    return 0;
}
