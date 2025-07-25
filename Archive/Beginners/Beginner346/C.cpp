#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, K;
    cin >> N >> K;

    set<long long> A;
    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        if (x <= K) A.insert(x);
    }

    long long allSum = K * (K + 1) / 2;
    for (auto x : A) {
        allSum -= x;
    }
    cout << allSum << endl;

    return 0;
}
