#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q; cin >> Q;
    deque<int> dq;
    while (Q--) {
        int t, x; cin >> t >> x;
        if (t == 1) {
            dq.push_front(x);
        } else if (t == 2) {
            dq.push_back(x);
        } else {
            cout << dq[x - 1] << endl;
        }
    }

    return 0;
}
