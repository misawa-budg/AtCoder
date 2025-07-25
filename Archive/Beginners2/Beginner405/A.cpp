#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, X; cin >> R >> X;
    if (X == 1) {
        if (1600 <= R && R <= 2999) cout << "Yes\n";
        else cout << "No\n";
    } else {
        if (1200 <= R && R <= 2399) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
