#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        M -= a;
    }

    cout << ((M < 0) ? "No" : "Yes") << endl;

    return 0;
}
