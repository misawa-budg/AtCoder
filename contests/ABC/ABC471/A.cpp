#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B; cin >> A >> B;

    if (A + B == 9 ||
        A - B == 9 ||
        A * B == 9 ||
        A == 9 * B) {
            cout << "Nine\n";
    } else {
        cout << "Nein\n";
    }

    return 0;
}
