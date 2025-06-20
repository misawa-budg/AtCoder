#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C; cin >> R >> C;

    int distance = max(abs(R - 8), abs(C - 8));

    if (distance % 2 == 0) {
        cout << "white\n";
    } else {
        cout << "black\n";
    }

    return 0;
}
