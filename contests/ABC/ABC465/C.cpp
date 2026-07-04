#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string S; cin >> S;

    deque<int> dq;
    bool rev = false;

    for (int k = 1; k <= N; k++) {
        if (rev) dq.push_front(k);
        else dq.push_back(k);

        if (S[k-1] == 'o') rev = !rev;
    }

    if (rev) {
        for (auto it = dq.rbegin(); it != dq.rend(); it++) {
            cout << *it << ' ';
        }
    } else {
        for (auto it = dq.begin(); it != dq.end(); it++) {
            cout << *it << ' ';
        }
    }
    cout << '\n';

    return 0;
}
