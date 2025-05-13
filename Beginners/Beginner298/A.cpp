#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string S; cin >> S;

    int good = 0, bad = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'o') good++;
        else if (S[i] == 'x') bad++;
    }

    if (good > 0 && bad == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}