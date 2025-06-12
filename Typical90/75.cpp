#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N; cin >> N;

    long long tmp = N;
    int k = 0;
    for (long long i = 2; i * i <= tmp; i++) {
        while (tmp % i == 0) {
            k++;
            tmp /= i;
        }
    }
    if (tmp > 1) k++;

    if (k <= 1) {
        cout << 0 << endl;
        return 0;
    }

    int m = 0;
    long long power2 = 1;
    while (power2 < k) {
        power2 *= 2;
        m++;
    }

    cout << m << endl;

    return 0;
}
