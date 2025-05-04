#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string S = "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
    cout << "3.";
    for (int i = 1; i <= N; i++) {
        cout << S[i - 1];
    }
    cout << endl;

    return 0;
}