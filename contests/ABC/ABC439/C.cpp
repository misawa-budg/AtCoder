#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> c(N + 1, 0);

    for (int x = 1; x * x <= N; x++) {
        for (int y = x + 1; x * x + y * y <= N; y++) {
            c[x * x + y * y]++;
        }
    }

    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        if (c[i] == 1) ans.push_back(i);
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        if (i) cout << ' ';
        cout << ans[i];
    } cout << '\n';

    return 0;
}
