#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> P(N);
    vector<set<int>> F(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        int count; cin >> count;
        for (int j = 0; j < count; j++) {
            int f; cin >> f;
            F[i].insert(f);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;

            if (P[i] < P[j]) continue;

            bool contains = true;
            for (int f : F[i]) {
                if (F[j].count(f) == 0) {
                    contains = false;
                    break;
                }
            }
            if (!contains) continue;

            if (P[i] > P[j] || F[j].size() > F[i].size()) {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
