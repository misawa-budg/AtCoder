#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    int base = 1;
    for (int i = 0; i < N; i++) base *= 2;

    cout << base - 2 * N << '\n';

    return 0;
}
