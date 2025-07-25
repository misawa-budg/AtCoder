#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<string> S(N); for (int i = 0; i < N; ++i) cin >> S[i];

    map<string, int> cnt;
    for (int i = 0; i < N; i++) {
        int count = cnt[S[i]];

        if (count == 0) {
            cout << S[i] << '\n';
        } else {
            cout << S[i] << '(' << count << ')' << '\n';
        }

        cnt[S[i]]++;
    }

    return 0;
}
