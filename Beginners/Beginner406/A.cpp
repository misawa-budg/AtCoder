#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, C, D; cin >> A >> B >> C >> D;

    if (C < A) {
        cout << "Yes" << endl;
    } else if (A == C) {
        if (D < B) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        cout << "No" << endl;
    }

    return 0;
}
