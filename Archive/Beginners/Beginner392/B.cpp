#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> A(M);

    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int index = 0;
    vector<int> B;
    for (int i = 1; i <= N; i++) {
        if (index < M && A[index] == i) {
            index++;
        } else {
            B.push_back(i);
        }
    }

    cout << B.size() << endl;
    for (int i = 0; i < B.size(); i++) {
        if (i) cout << " ";
        cout << B[i];
    }
    cout << endl;

    return 0;
}
