#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;
    queue<int> q;

    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '#') {
            q.push(i + 1);
        }
    }

    while (!q.empty()) {
        cout << q.front() << ','; q.pop();
        cout << q.front() << '\n'; q.pop();
    }

    return 0;
}
