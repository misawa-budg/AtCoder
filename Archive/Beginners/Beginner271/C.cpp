#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N), has(N + 2, 0);
    int spare = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] >= N + 1) spare++;
        else if (has[A[i]]) spare++;
        else has[A[i]] = 1;
    }

    int l = 1, r = N+1;
    while (true) {
        while (has[l]) l++;
        while (!has[r] && r > 0) r--;

        if (spare >= 2) {
            spare -= 2;
            has[l] = 1;
        } else {
            if (l >= r) break;
            has[r] = 0;
            spare++;
        }
    }

    cout << l-1 << endl;

    return 0;
}
