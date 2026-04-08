#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    string S, T; cin >> S >> T;

    int result = INT_MAX;
    for (int i = 0; i <= N - M; i++) {
        string str = T;
        int count = 0;
        for (int j = 0; j < M; j++) {
            count += ((S[i + j] - '0') - (str[j] - '0') + 10) % 10;
        }
        result = min(result, count);
    }

    cout << result << '\n';

    return 0;
}
