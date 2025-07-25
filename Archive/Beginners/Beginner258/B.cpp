#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<string> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    char maxChar = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            maxChar = max(maxChar, A[i][j]);
        }
    }

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] != maxChar) continue;

            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;

                    string s;
                    for (int k = 0; k < N; k++) {
                        int ni = ((i + dx * k) % N + N) % N;
                        int nj = ((j + dy * k) % N + N) % N;
                        s += A[ni][nj];
                    }
                    ans = max(ans, stoll(s));
                }
            }
        }
    }
    cout << ans << "\n";

    return 0;
}
