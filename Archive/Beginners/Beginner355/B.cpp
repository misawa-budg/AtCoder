#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    vector<int> B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];

    vector<int> C(A);
    for (auto x : B) C.push_back(x);
    sort(C.begin(), C.end());

    set<int> st(A.begin(), A.end());
    for (int i = 0; i < N + M - 1; i++) {
        if (st.contains(C[i]) && st.contains(C[i + 1])) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}
