#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q; cin >> Q;
    multiset<int> ms;
    while (Q--) {
        int query; cin >> query;
        if (query == 1) {
            int x; cin >> x;
            ms.insert(x);
        } else {
            cout << *ms.begin() << endl;
            ms.erase(ms.begin());
        }
    }

    return 0;
}
