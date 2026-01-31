#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, K; cin >> N >> K;
    long long year = -1;

    long long eat = 0;
    while (eat < K) {
        eat += N;
        N++;
        year++;
    }
    cout << year << "\n";

    return 0;
}
