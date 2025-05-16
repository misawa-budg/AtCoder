#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;
    vector<int> red(N, 0), yellow(N, 0);

    for (int i = 0; i < Q; i++) {
        int query, player; cin >> query >> player;
        if (query == 1) yellow[player - 1]++;
        else if (query == 2) red[player - 1]++;
        else {
            if (yellow[player - 1] >= 2 || red[player - 1] >= 1) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
