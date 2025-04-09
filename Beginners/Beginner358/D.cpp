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

    multiset<int> st;
    for (int i = 0; i < N; i++) {
        st.insert(A[i]);
    }

    long long ans = 0;
    for (int i = 0; i < M; i++) {
        auto it = st.lower_bound(B[i]);
        if (it == st.end()) {
            cout << -1 << endl;
            return 0;
        } else {
            ans += *it;
            st.erase(it);
        }
    }

    cout << ans << endl;

    return 0;
}
