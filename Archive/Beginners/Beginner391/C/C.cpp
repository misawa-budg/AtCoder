#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> pigeons(N + 1);
    vector<int> nests(N + 1);
    for (int i = 0; i < N + 1; i++) {
        pigeons[i] = i;
        nests[i] = 1;
    }

    int MultiplePigeonsNestCount = 0;
    for (int i = 0; i < Q; i++) {
        int query;
        cin >> query;
        if (query == 1) {
            int pigeon, nest;
            cin >> pigeon >> nest;

            nests[pigeons[pigeon]]--;
            if (nests[pigeons[pigeon]] == 1) MultiplePigeonsNestCount--;

            pigeons[pigeon] = nest;

            nests[nest]++;
            if (nests[nest] == 2) MultiplePigeonsNestCount++;

        } else {
            cout << MultiplePigeonsNestCount << endl;
        }
    }

    return 0;
}
