#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, C, D; cin >> A >> B >> C >> D;
    if (C < A) {
        cout << "Yes\n";
    } else if (C == A) {
        if (D < B) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    } else {
        cout << "No\n";
    }

    return 0;
}
