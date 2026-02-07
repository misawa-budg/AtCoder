#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<pair<int, int>> rank(N);
    for (int i = 0; i < N; i++) {
        int A; cin >> A;
        rank[i] = {A, i + 1};
    }

    sort(rank.begin(), rank.end());

    for (int i = 0; i < 3; i++) {
        if (i) cout << " ";
        cout << rank[i].second;
    }
    cout << '\n';

    return 0;
}
