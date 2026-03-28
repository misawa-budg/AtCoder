#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    vector<int> member(M+1, 0);
    for (int i = 0; i < N; i++) {
        member[B[i]]++;
        member[A[i]]--;
    }

    for (int i = 1; i <= M; i++) {
        cout << member[i] << '\n';
    }

    return 0;
}
