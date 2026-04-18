#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int>F(N); for (int i = 0; i < N; i++) cin >> F[i];

    set<int> seen;
    for (int i = 0; i < N; i++) {
        seen.insert(F[i]);
    }

    if (seen.size() != N) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }

    vector<bool> wear(M, false);
    for (int i = 0; i < N; i++) {
        wear[F[i]-1] = true;
    }

    for (int i = 0; i < M; i++) {
        if (!wear[i]) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";

    return 0;
}
