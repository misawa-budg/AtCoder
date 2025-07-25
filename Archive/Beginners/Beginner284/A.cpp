#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<string> S(N); for (int i = 0; i < N; ++i) cin >> S[i];

    for (int i = S.size() - 1; i >= 0; --i) {
        cout << S[i] << endl;
    }

    return 0;
}
