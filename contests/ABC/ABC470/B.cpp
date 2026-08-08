#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> C(N); for (int i = 0; i < N; i++) cin >> C[i];

    vector<int> freq(N + 1, 0);
    for (int i = 0; i < N; i++) {
        freq[C[i]]++;
    }

    int most = -1;
    for (int i = 1; i <= N; i++) {
        most = max(most, freq[i]);
    }

    cout << N - most << '\n';

    return 0;
}
