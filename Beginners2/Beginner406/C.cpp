#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> P(N); for (int i = 0; i < N; i++) cin >> P[i];
    vector<pair<char, long long>> runLengths;
    for (int i = 0; i < N - 1; i++) {
        if (P[i] < P[i + 1]) {
            if (runLengths.empty() || runLengths.back().first != '<') {
                runLengths.emplace_back('<', 1);
            } else runLengths.back().second++;
        }
        if (P[i] > P[i + 1]) {
            if (runLengths.empty() || runLengths.back().first != '>') {
                runLengths.emplace_back('>', 1);
            } else runLengths.back().second++;
        }
    }

    long long ans = 0;
    for (int i = 1; i < runLengths.size() - 1; i++) {
        if (runLengths[i].first == '>') {
            ans += runLengths[i - 1].second * runLengths[i + 1].second;
        }
    }
    cout << ans << '\n';

    return 0;
}
