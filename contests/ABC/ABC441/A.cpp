#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int P, Q; cin >> P >> Q;
    int X, Y; cin >> X >> Y;

    if ((P <= X && X < P + 100) && (Q <= Y && Y < Q + 100)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
