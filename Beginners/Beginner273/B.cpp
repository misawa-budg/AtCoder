#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X, K; cin >> X >> K;

    long long tmp = X;
    for (int i = 0; i < K; i++) {
        int base = 10;

        int digit = X % base;
        if (digit >= 5) X -= digit, X += base;
        else if (digit < 5) X -= digit;
        X /= base;
    }
    for (int i = 0; i < K; i++) {
        X *= 10;
    }

    cout << X << endl;

    return 0;
}
