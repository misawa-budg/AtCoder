#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    vector<int> runners(N, 0);
    for (int i = 0; i < N; i++) {
        int increase = A[i];
        for (int j = 0; j <= i; j++) {
            runners[j] += increase;
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (runners[i] >= 4) ans++;
    }

    cout << ans << endl;

    return 0;
}
