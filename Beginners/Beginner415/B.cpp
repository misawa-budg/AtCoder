#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;
    vector<int> index;
    for (int i = 0; i < (int)S.size(); i++) {
        if (S[i] == '#') index.push_back(i);
    }

    for (int i = 0; i < (int)index.size(); i+=2) {
        cout << index[i] + 1 << ',' << index[i + 1] + 1 << '\n';
    }

    return 0;
}
