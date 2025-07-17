#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q; cin >> Q;
    queue<int> q;
    for (;Q--;) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x;
            q.push(x);
        } else {
            cout << q.front() << endl;
            q.pop();
        }
    }

    return 0;
}
