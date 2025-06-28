#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S; cin >> N >> S;
    vector<int> T(N); for (int i = 0; i < N; i++) cin >> T[i];

    int last = 0;
    for (int i = 0; i < N; i++) {
        if (T[i] - last > S) {
            cout << "No" << endl;
            return 0;
        }
        last = T[i];
    }
    cout << "Yes" << endl;

    return 0;
}
