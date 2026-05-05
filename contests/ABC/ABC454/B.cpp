#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> F(N); for (int i = 0; i < N; i++) cin >> F[i];

    vector<bool> kinds(M + 1, false);
    int all = 0;
    for (int i = 0; i < N; i++) {
        if (!kinds[F[i]]) all++;
        kinds[F[i]] = true;
    }

    if (all != N) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }

    for (int i = 1; i <= M; i++) {
        if (!kinds[i]) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";

    return 0;
}
