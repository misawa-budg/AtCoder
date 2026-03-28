#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q; cin >> Q;
    multiset<int> trees;
    while (Q--) {
        int type; cin >> type;
        int h; cin >> h;


        if (type == 1) {
            trees.insert(h);
        } else if (type == 2) {
            auto border = trees.lower_bound(h);
            while (*border == h && border != trees.end()) border++;
            trees.erase(trees.begin(), border);
        }
        cout << trees.size() << '\n';
    }

    return 0;
}
