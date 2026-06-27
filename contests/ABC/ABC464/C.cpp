#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> A(N), D(N), B(N), count(N + 1, 0);
    vector<vector<int>> changes(M + 1);
    int kinds = 0;

    for (int i = 0; i < N; i++) {
        cin >> A[i] >> D[i] >> B[i];
        if (D[i] > 1) changes[D[i]].push_back(i);

        int color = (D[i] == 1) ? B[i] : A[i];
        count[color]++;
        if (count[color] == 1) kinds++;
    }

    cout << kinds << '\n';

    for (int day = 2; day <= M; day++) {
        for (int i : changes[day]) {
            count[A[i]]--;
            if (count[A[i]] == 0) kinds--;
            count[B[i]]++;
            if (count[B[i]] == 1) kinds++;
        }

        cout << kinds << '\n';
    }

    return 0;
}
