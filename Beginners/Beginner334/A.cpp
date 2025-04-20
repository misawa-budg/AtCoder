#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int B, G; cin >> B >> G;

    if (B > G) {
        cout << "Bat" << endl;
    } else {
        cout << "Glove" << endl;
    }

    return 0;
}
