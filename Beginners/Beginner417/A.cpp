#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, A, B; cin >> N >> A >> B;
    string S; cin >> S;
    for (int i = A; i < N - B; i++) {
        cout << S[i];
    }
    cout << endl;

    return 0;
}
