#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;

    vector<int> columns(N + 1, 0);
    vector<int> counts(Q + 1, 0);
    counts[0] = N;

    int removed = 0;
    int maxQ = Q;

    while (Q--) {
        int query; cin >> query;
        
        if (query == 1) {
            int x; cin >> x;

            counts[columns[x] + 1]++;
            columns[x]++;

            if (counts[removed + 1] == N) removed++;

        } else if (query == 2) {
            int y; cin >> y;

            int target = y + removed;
            if (target > maxQ) {
                cout << 0 << '\n';
            } else {
                cout << counts[target] << '\n';
            }
        }
    }

    return 0;
}
