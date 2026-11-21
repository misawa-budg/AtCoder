#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S; cin >> N >> S;

    int completePos = -1;
    bool hasA = false, hasB = false, hasC = false;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'A') hasA = true;
        if (S[i] == 'B') hasB = true;
        if (S[i] == 'C') hasC = true;
        if (hasA && hasB && hasC) {
            completePos = i;
            break;
        }
    }

    if (completePos == -1) {
        cout << 0 << endl;
        return 0;
    }

    int completePosBack = -1;
    hasA = false; hasB = false; hasC = false;
    for (int i = N-1; i >= 0; i--) {
        if (S[i] == 'A') hasA = true;
        if (S[i] == 'B') hasB = true;
        if (S[i] == 'C') hasC = true;
        if (hasA && hasB && hasC) {
            completePosBack = i;
            break;
        }
    }

    long long ans = 0;
    int lastA = 0, lastB = 0, lastC = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'A') lastA = i;
        if (S[i] == 'B') lastB = i;
        if (S[i] == 'C') lastC = i;

        if (i + 1 > completePosBack) continue;

        int m = min(lastA, min(lastB, lastC));

        int lo = completePos;
        int hi = m - 1;
        if (lo <= hi) {
            ans += hi - lo + 1;
        }
    }

    cout << ans << endl;
    return 0;
}
