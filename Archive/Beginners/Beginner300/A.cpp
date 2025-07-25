#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, A, B; cin >> N >> A >> B;
    vector<int> C(N); for (int i = 0; i < N; ++i) cin >> C[i];

    int target = A + B;
    for (int i = 0; i < N; i++) {
        if (C[i] == target) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    return 0;
}
