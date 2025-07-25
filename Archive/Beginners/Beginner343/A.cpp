#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B; cin >> A >> B;
    for (int i = 0; i < 10; i++) {
        if (i != A + B) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}
