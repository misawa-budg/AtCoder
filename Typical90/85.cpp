#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long K; cin >> K;
    long long count = 0;

    for (long long a = 1; a * a * a <= K; a++) {
        if (K % a != 0) continue;
        long long K1 = K / a;
        for (long long b = a; b * b <= K1; b++) {
            if (K1 % b != 0) continue;
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
