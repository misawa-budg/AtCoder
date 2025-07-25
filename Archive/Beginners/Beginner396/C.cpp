#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<long long> B(N), W(M);
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> W[i];
    }

    sort(B.rbegin(), B.rend());
    sort(W.rbegin(), W.rend());

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        long long black, white;
        if (i >= M) {
            black = B[i], white = 0;
        } else {
            black = B[i], white = W[i];
        }

        if (black > 0 && white > 0) {
            ans += black + white;
        } else if (black > 0 && white <= 0) {
            ans += black;
        } else if (black < 0 && white > 0) {
            if (abs(black) < white) {
                ans += black + white;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
