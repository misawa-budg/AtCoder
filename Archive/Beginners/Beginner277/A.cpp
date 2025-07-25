#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X; cin >> N >> X;
    vector<int> P(N); for (int i = 0; i < N; i++) cin >> P[i];

    for (int i = 0; i < N; i++) {
        if (P[i] == X) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    return 0;
}
