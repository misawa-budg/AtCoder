#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B; cin >> A >> B;

    int base = A;
    for (int i = 1; i < B; i++) {
        A *= base;

    }
    cout << A << endl;

    return 0;
}
