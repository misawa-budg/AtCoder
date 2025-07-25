#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;

    map<string, int> mp;
    queue<string> q;
    q.push(S);
    mp[S] = 0;

    while (!q.empty()) {
        string s = q.front(); q.pop();
        if (s == "atcoder") {
            cout << mp[s] << endl;
            return 0;
        }

        for (int i = 1; i < 7; i++) {
            string t = s;
            swap(t[i-1], t[i]);
            if (mp.find(t) == mp.end()) {
                mp[t] = mp[s] + 1;
                q.push(t);
            }
        }
    }

    return 0;
}
