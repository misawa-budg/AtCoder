#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<string> S(N), T(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    for (int i = 0; i < N; i++) cin >> T[i];

    int minCount = INT_MAX;
    vector<string> rotated = S;
    for (int i = 0; i < 4; i++) {
        int count = 0;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (rotated[j][k] != T[j][k]) count++;
            }
        }
        minCount = min(minCount, count + i);
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                rotated[k][N - 1 - j] = S[j][k];
            }
        }
        S = rotated;
    }
    cout << minCount << '\n';

    return 0;
}
