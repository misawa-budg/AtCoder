#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    long long base = 1;
    for (int i = 0; i < N; i++) {
        base *= 2;
    }

    cout << base << endl;

    return 0;
}
