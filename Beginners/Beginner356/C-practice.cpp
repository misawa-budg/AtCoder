#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    vector<int> keys(M, 0);
    vector<int> results(M, 0);
    for (int i = 0; i < M; i++) {
        int keyNum;
        cin >> keyNum;
        for (int j = 0; j < keyNum; j++) {
            int key;
            cin >> key;
            key--;
            keys[i] |= (1 << key);
        }

        char result;
        cin >> result;
        results[i] = (result == 'o') ? 1 : 0;
    }

    int ans = 0;
    for (int bit = 0; bit < (1 << N); bit++) {
        bool judge = true;
        for (int i = 0; i < M; i++) {
            int matchKeyCount = __builtin_popcount(bit & keys[i]);
            if (matchKeyCount >= K && results[i] == 0) {
                judge = false;
                break;
            }
            if (matchKeyCount < K && results[i] == 1) {
                judge = false;
                break;
            }
        }
        if (judge) ans++;
    }

    cout << ans << endl;

    return 0;
}
