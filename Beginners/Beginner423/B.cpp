#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> L(N); for (int i = 0; i < N; i++) cin >> L[i];

    int left = N;
    for (int i = 0; i < N; i++) {
        if (L[i] == 1) {
            left = i;
            break;
        }
    }

    int right = -1;
    for (int i = N - 1; i >= 0; i--) {
        if (L[i] == 1) {
            right = i;
            break;
        }
    }

    cout << max(0, right - left) << '\n';

    return 0;
}
