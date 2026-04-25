#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;

    vector<int> up(2 * N + 1, 0);
    vector<int> down(2 * N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        up[N + i] = i;
        down[i] = N + i;
    }

    for (int q = 0; q < Q; ++q) {
        int C, P;
        cin >> C >> P;

        int prev_down = down[C];
        up[prev_down] = 0;

        down[C] = P;
        up[P] = C;
    }

    for (int i = 1; i <= N; ++i) {
        int count = 0;
        int curr = up[N + i];
        
        while (curr != 0) {
            count++;
            curr = up[curr];
        }
        
        cout << count << (i == N ? "" : " ");
    }
    cout << '\n';

    return 0;
}
