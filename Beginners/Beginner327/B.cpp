#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long B; cin >> B;

    if (B == 1) {
        cout << "1" << endl;
        return 0;
    }

    for (long long A = 1; A <= 15; A++) {
        long long pow = 1;
        for (long long count = 0; count < A; count++) {
            pow *= A;
        }
        if (pow == B) {
            cout << A << endl;
            return 0;
        } else if (pow > B) {
            break;
        }
    }
    cout << "-1" << endl;

    return 0;
}
