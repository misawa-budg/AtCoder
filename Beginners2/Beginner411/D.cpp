#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;
    vector<pair<int, string>> history;
    history.emplace_back(-1, "");
    vector<int> ptr(N + 1, 0);

    int serverPtr = 0;
    for (int i = 0; i < Q; i++) {
        int query; cin >> query;
        if (query == 1) {
            int p; cin >> p;
            ptr[p] = serverPtr;
        } else if (query == 2) {
            int p; cin >> p;
            string s; cin >> s;
            history.emplace_back(ptr[p], s);
            ptr[p] = history.size() - 1;
        } else {
            int p; cin >> p;
            serverPtr = ptr[p];
        }
    }

    vector<string> result;
    int curPtr = serverPtr;
    while (curPtr != -1) {
        result.push_back(history[curPtr].second);
        curPtr = history[curPtr].first;
    }

    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i];
    } cout << '\n';


    return 0;
}
