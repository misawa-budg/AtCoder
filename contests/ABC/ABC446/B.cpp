#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;

    vector<bool> used(M, false);
    for (int i = 0; i < N; i++) {
        bool found = false;
        int len; cin >> len;
        vector<int> juice(len);
        for (int j = 0; j < len; j++) {
            cin >> juice[j];
        }

        for (int j = 0; j < len; j++) {
            if (!used[juice[j]]) {
                cout << juice[j] << '\n';
                used[juice[j]] = true;
                found = true;
                break;
            }
        }
        if (!found) cout << 0 << '\n';
    }

    return 0;
}
