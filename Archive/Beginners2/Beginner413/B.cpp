#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<string> S(N); for (int i = 0; i < N; i++) cin >> S[i];

    set<string> ans;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            string combined = S[i] + S[j];
            ans.insert(combined);
        }
    }
    cout << ans.size() << '\n';

    return 0;
}
