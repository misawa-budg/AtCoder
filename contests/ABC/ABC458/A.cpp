#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;
    int N; cin >> N;

    cout << S.substr(N, S.size() - 2 * N) << '\n';

    return 0;
}
