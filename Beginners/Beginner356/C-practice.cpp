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
        int keyCount;
        cin >> keyCount;
        for (int j = 0; j < keyCount; j++) {
            int key;
            cin >> key;
            key--;
            keys[i] |= (1 << key);
        }
        char result;
        cin >> result;
        results[i] = (result == 'o') ?  1 : 0;
    }

    int patterns = 0;
    for (int bit = 0; bit < (1 << N); bit++) {
        bool judge = true;
        for (int i = 0; i < M; i++) {
            int trueKeysCount = __builtin_popcount(bit & keys[i]);
            if (trueKeysCount >= K && !results[i]) {
                judge = false;
                break;
            }
            if (trueKeysCount < K && results[i]) {
                judge = false;
                break;
            }
        }
        if (judge) patterns++;
    }

    cout << patterns << endl;

    return 0;
}
