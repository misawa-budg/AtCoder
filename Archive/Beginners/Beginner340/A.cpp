#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, D; cin >> A >> B >> D;
    int number = A;
    while (number <= B) {
        cout << number << " ";
        number += D;
    }
    cout << endl;

    return 0;
}
