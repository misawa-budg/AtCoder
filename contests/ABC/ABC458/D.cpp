#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X, Q; cin >> X >> Q;
    vector<long long> A(Q), B(Q);
    for (int i = 0; i < Q; i++) {
        cin >> A[i] >> B[i];
    }

    multiset<long long> ms;

    ms.insert(X);
    auto mid = ms.begin();

    for (int i = 0; i < Q; i++) {
        long long a = A[i], b = B[i];
        ms.insert(A[i]);
        ms.insert(B[i]);

        if (a < *mid && b < *mid) mid--;
        else if (a >= *mid && b >= *mid) mid++;

        cout << *mid << '\n';
    }

    return 0;
}
