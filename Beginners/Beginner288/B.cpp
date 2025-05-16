#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;
    vector<string> S(N); for (int i = 0; i < N; i++) cin >> S[i];

    set<string> ans;
    for (int i = 0; i < K; i++) ans.insert(S[i]);

    for (auto s : ans) cout << s << endl;

    return 0;
}
