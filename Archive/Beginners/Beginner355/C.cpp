#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T;
    cin >> N >> T;
    vector<int> rows(N);
    vector<int> cols(N);
    vector<int> diag(2);

    for (int i = 0; i < T; i++) {
        int num;
        cin >> num;
        int y = (num - 1) / N;
        int x = (num - 1) % N;

        if (++rows[y] == N ||
            ++cols[x] == N ||
            y == x && ++diag[0] == N ||
            y + x == N - 1 && ++diag[1] == N) {
                cout << i + 1 << endl;
                return 0;
            }
    }

    cout << -1 << endl;

    return 0;
}
