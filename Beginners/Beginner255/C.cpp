#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X, A, D, N; cin >> X >> A >> D >> N;

    if (D == 0) {
        cout << abs(X - A) << '\n';
        return 0;
    }

    long long left = A, right = A + (N - 1) * D;
    if (left > right) swap(left, right);

    if (X <= left) {
        cout << left - X << '\n';
    } else if (right <= X) {
        cout << X - right << '\n';
    } else {
        long long DAbs = abs(D);
        long long rem = (X - left) % DAbs;
        cout << min(rem, DAbs - rem) << '\n';
    }

    return 0;
}
