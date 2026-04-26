#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> counts(N + 1, 0);

    for (int x = 1; x * x <= N; x++) {
        for (int y = x + 1; x * x + y * y <= N; y++) {
            counts[x * x + y * y]++;
        }
    }

    int count = 0;
    for (int i = 1; i <= N; i++) if (counts[i] == 1) count++;
    cout << count << '\n';

    for (int i = 1; i <= N; i++) {
        if (counts[i] == 1) {
            cout << i << ' ';
        }
    }
    cout << '\n';

    return 0;
}
