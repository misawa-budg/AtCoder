#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q; cin >> Q;
    deque<int> dq;
    for (int i = 0; i < Q; i++) {
        int query; cin >> query;

        if (query == 1) {
            int x; cin >> x;
            dq.push_back(x);
        } else {
            cout << dq.front() << endl;
            dq.pop_front();
        }
    }

    return 0;
}
