#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;

    int count = 0;
    while (M != 0) {
        int x = N % M;
        M = x;
        count++;
    }

    cout << count << '\n';

    return 0;
}
