#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    set<int> S;
    for (int i = 1; i <= N; i++) S.insert(i);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        S.erase(b);
    }

    if (S.size() != 1) {
        cout << -1 << endl;
    } else {
        cout << *S.begin() << endl;
    }

    return 0;
}
