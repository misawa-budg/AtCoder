#include <bits/stdc++.h>
using namespace std;

long long Lmax = 1000000000000000000LL; // 10^18

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B; cin >> A >> B;
    long long gcd = __gcd(A, B);
    long long tmp = (A / gcd);
    if ((__int128)tmp * B > Lmax) {
        cout << "Large" << endl;
    } else {
        cout << tmp * B << endl;
    }

    return 0;
}
