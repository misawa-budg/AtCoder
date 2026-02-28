#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;

    if ((N - M) >= N / 2) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
