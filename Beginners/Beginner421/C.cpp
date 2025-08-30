#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string S; cin >> S;

    vector<int> A, B;
    for (int i = 0; i < 2 * N; i++) {
        if (S[i] == 'A') A.push_back(i);
        else B.push_back(i);
    }

    long long cost1 = 0;
    // ABABAB...
    for (int i = 0; i < N; i++) {
        cost1 += llabs((long long)A[i] - (2LL * i));
    }
    long long cost2 = 0;
    // BABABA...
    for (int i = 0; i < N; i++) {
        cost2 += llabs((long long)A[i] - (2LL * i + 1));
    }

    cout << min(cost1, cost2) << endl;

    return 0;
}
