#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;

    vector<pair<int, string>> history;
    history.push_back({-1, ""});

    int serverPtr = 0;
    vector<int> pcPtr(N + 1, 0);

    for (int i = 0; i < Q; i++) {
        int query; cin >> query;
        if (query == 1) {
            int p; cin >> p;
            pcPtr[p] = serverPtr;
        } else if (query == 2) {
            int p; cin >> p;
            string s; cin >> s;
            history.push_back({pcPtr[p], s});
            pcPtr[p] = history.size() - 1;
        } else {
            int p; cin >> p;
            serverPtr = pcPtr[p];
        }
    }

    vector<string> results;
    int curPtr = serverPtr;

    while (curPtr != -1) {
        results.push_back(history[curPtr].second);
        curPtr = history[curPtr].first;
    }

    for (int i = results.size() - 1; i >= 0; i--) {
        cout << results[i];
    }
    cout << endl;

    return 0;
}
