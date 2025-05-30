#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        mp[a]++;
    }

    for (auto it = mp.rbegin(); it != mp.rend(); it++) {
        cout << it->second << endl;
    }
    for (int i = 0; i < N - mp.size(); i++) cout << 0 << endl;

    return 0;
}
