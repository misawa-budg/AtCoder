#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> A(M), B(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
    }

    vector<set<int>> haveRelation(N + 1);
    for (int i = 0; i < M; i++) {
        haveRelation[A[i]].insert(B[i]);
        haveRelation[B[i]].insert(A[i]);
    }

    for (int i = 1; i <= N; i++) {
        long long patterns = 0;
        long long dontHaveRelation = N - 1 - haveRelation[i].size();
        patterns = (dontHaveRelation * (dontHaveRelation - 1) * (dontHaveRelation - 2)) / 6;
        cout << patterns;
        if (i != N) {
            cout << " ";
        }
    }
    cout << "\n";

    return 0;
}
