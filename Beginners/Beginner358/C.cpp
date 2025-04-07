#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<char>> stores(N, vector<char>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> stores[i][j];
        }
    }

    int cost = 10;
    for (int bit = 1; bit < (1 << N); bit++) {
        vector<int> selectedStores;
        for (int i = 0; i < N; i++) {
            if (bit & (1 << i)) {
                selectedStores.push_back(i);
            }
        }

        vector<int> coverage(M);
        for (int store : selectedStores) {
            for (int j = 0; j < M; j++) {
                if (stores[store][j] == 'o') {
                    coverage[j] = 1;
                }
            }
        }

        bool allCovered = true;
        for (int j = 0; j < M; j++) {
            if (coverage[j] == 0) {
                allCovered = false;
                break;
            }
        }

        if (allCovered) {
            cost = min(cost, (int)selectedStores.size());
        }
    }

    cout << cost << endl;

    return 0;
}
