#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B; cin >> A >> B;

    long long ansA = A;
    for (int i = 1; i < B; i++) {
        ansA *= A;
    }
    long long ansB = B;
    for (int i = 1; i < A; i++) {
        ansB *= B;
    }

    cout << ansA + ansB << endl;

    return 0;
}
