#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;
    string S; cin >> S;
    vector<int> nextToCount(N, 0);

    for (int i = 1; i < N; i++) {
        if (S[i] == S[i - 1]) {
            nextToCount[i] = nextToCount[i - 1] + 1;
        } else {
            nextToCount[i] = nextToCount[i - 1];
        }
    }

    for (int i = 0; i < Q; i++) {
        int L, R; cin >> L >> R;
        L--; R--;
        cout << nextToCount[R] - nextToCount[L] << endl;
    }

    return 0;
}