#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        string S; cin >> S;
        vector<long long> X(N), Y(N - 1);
        for (int i = 0; i < N; i++) cin >> X[i];
        for (int i = 0; i < N - 1; i++) cin >> Y[i];

        long long rainy = S[0] == 'S' ? -X[0] : 0;
        long long sunny = S[0] == 'R' ? -X[0] : 0;

        for (int i = 1; i < N; i++) {
            long long costr = S[i] == 'S' ? X[i] : 0;
            long long costs = S[i] == 'R' ? X[i] : 0;

            long long nextr = max(rainy, sunny) - costr;
            long long nexts = max(rainy + Y[i - 1], sunny) - costs;

            rainy = nextr;
            sunny = nexts;
        }

        cout << max(rainy, sunny) << '\n';
    }

    return 0;
}
