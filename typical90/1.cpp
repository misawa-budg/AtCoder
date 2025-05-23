#include <bits/stdc++.h>
using namespace std;

int N, L, K;
int piece;
bool check(int x, vector<int>& A)
{
    int piece = 0, prev = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] - prev >= x) {
            piece++;
            prev = A[i];
        }
    }

    if (L - prev >= x) piece++;

    return piece >= K + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> L >> K;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    int lo = 0, hi = L;
    while (hi - lo > 1) {
        int mid = (lo + hi) / 2;
        piece = 0;
        if (check(mid, A)) {
            lo = mid; 
        } else {
            hi = mid;
        }
    }

    cout << lo << endl;

    return 0;
}