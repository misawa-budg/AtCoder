#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;

    for (int i = 0; i < N; i++) {
        if (i < M % N) {
            cout << M / N + 1 << '\n';
        } else {
            cout << M / N << '\n';
        }
    }

    return 0;
}
