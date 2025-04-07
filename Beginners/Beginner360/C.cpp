#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> W(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> W[i];
    }

    map<int, vector<int>> mp;
    for (int i = 1; i <= N; i++) {
        mp[A[i-1]].push_back(W[i-1]);
    }

    int ans = 0;
    for (auto& [key, value] : mp) {
        if (value.size() > 1) {
            sort(value.begin(), value.end());
            for (int i = 0; i < value.size() - 1; i++) {
                ans += value[i];
            }
        }
    }

    cout << ans << endl;

    return 0;
}
