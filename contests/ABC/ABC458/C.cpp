#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;

    long long count = 0;
    for (int i = 0; i < (int) S.size(); i++) {
        if (S[i] == 'C') count += min(i, (int)S.size() - i - 1) + 1;
    }

    cout << count << '\n';

    return 0;
}
