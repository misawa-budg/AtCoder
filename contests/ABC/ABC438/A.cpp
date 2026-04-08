#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int D, F; cin >> D >> F;
    while (F <= D) F += 7;
    cout << F - D << '\n';

    return 0;
}
