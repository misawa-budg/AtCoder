#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    map<int, vector<int>> cnt;
    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        cnt[input].push_back(i + 1);
    }

    int ans = -1;
    for (auto it = cnt.rbegin(); it != cnt.rend(); it++) {
        if (it->second.size() == 1) {
            ans = it->second[0];
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
