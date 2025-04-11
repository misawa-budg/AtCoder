#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<int, int> A;
    for (int i = 0; i < 7; i++) {
        int input;
        cin >> input;
        A[input]++;
    };

    int hasTrio = 0, hasPair = 0;
    for (auto& [key, value] : A) {
        if (!hasTrio && value >= 3) {
            hasTrio = 1;
        } else if (value >= 2) {
            hasPair = 1;
        }
    }

    if (hasTrio && hasPair) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
