#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    for (int i = 1; i <= N; i++) {
        if (i % 3 == 0) {
            cout << 'x';
        }
        else cout << 'o';
    }
    cout << endl;

    return 0;
}
