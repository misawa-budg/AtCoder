#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B; cin >> A >> B;
    vector<pair<int, int>> P = {
        {1,2}, {2,3},
        {4,5}, {5,6},
        {7,8}, {8,9}
    };

    for (auto [x, y] : P) {
        if (x == A && y == B) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}
