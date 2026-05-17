#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X, Q; cin >> X >> Q;

    multiset<long long> ms;
    ms.insert(X);
    auto mid = ms.begin();

    for (int i = 0; i < Q; i++) {
        int a, b; cin >> a >> b;
        ms.insert(a); ms.insert(b);

        int midNum = *mid;
        if (midNum > a && midNum > b) mid--;
        else if (midNum < a && midNum < b) mid++;

        cout << *mid << '\n';
    }

    return 0;
}
