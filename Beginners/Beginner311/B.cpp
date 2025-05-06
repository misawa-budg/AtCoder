#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D; cin >> N >> D;
    vector<string> S(N); for (int i = 0; i < N; i++) cin >> S[i];

    int ans = 0, tmp = 0;
    for (int i = 0; i < D; i++) {

        bool isFree = true;
        for (int j = 0; j < N; j++) {
            if (S[j][i] == 'x') {
                isFree = false;
                break;
            }
        }

        if (isFree) {
            tmp++;
        } else {
            tmp = 0;
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}
