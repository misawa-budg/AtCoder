#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> elements(9); for (int i = 0; i < 9; i++) cin >> elements[i];
    vector<tuple<int, int, int>> lines = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };
    vector<int> order(9); iota(order.begin(), order.end(), 0);
    int all = 0, disappointedCount = 0;
    do {
        all++;
        bool disappointed = false;
        for (auto [a, b, c] : lines) {
            if (elements[a] == elements[b] && order[a] < order[c] && order[b] < order[c]) {
                disappointed = true;
            } else if (elements[b] == elements[c] && order[b] < order[a] && order[c] < order[a]) {
                disappointed = true;
            } else if (elements[c] == elements[a] && order[c] < order[b] && order[a] < order[b]) {
                disappointed = true;
            }
        }
        if (!disappointed) disappointedCount++;
    } while (next_permutation(order.begin(), order.end()));

    cout << setprecision(20);
    cout << (double)disappointedCount / all << endl;

    return 0;
}
