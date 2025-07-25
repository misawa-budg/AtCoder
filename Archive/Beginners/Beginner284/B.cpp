#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;

    for (int i = 0; i < T; i++) {
        int N; cin >> N;
        vector<int> A(N); for (int j = 0; j < N; ++j) cin >> A[j];

        int odd = 0;
        for (int j = 0; j < N; j++) {
            if (A[j] % 2 == 1) odd++;
        }

        cout << odd << endl;
    }

    return 0;
}
