#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Y; cin >> Y;

    for (int i = 0; i <= 3; i++) {
        int year = Y + i;
        if (year % 4 == 2) {
            cout << year << '\n';
        }
    }

    return 0;
}
