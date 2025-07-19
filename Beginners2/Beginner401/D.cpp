#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    string T; cin >> T;

    int num = count(T.begin(), T.end(), 'o');

    if (num == K) {
        replace(T.begin(), T.end(), '?', '.');
        cout << T << endl;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        if (T[i] == 'o') {
            if (i - 1 >= 0 && T[i - 1] == '?') T[i - 1] = '.';
            if (i + 1 < N && T[i + 1] == '?') T[i + 1] = '.';
        }
    }
    string S = T;

    // 最大数配置してみる
    for (int i = 0; i < N; i++) {
        if (T[i] == '?') {
            if (i - 1 >= 0 && T[i - 1] == 'o') T[i] = '.';
            else if (i + 1 < N && T[i + 1] == 'o') T[i] = '.';
            else T[i] = 'o';
        }
    }
    int nNum = count(T.begin(), T.end(), 'o');

    if (nNum == K) {
        for (int i = 0; i < N; i++) {
            if (S[i] == '?') {
                int interval = 0;
                int start = i, j = i;
                while (j < N && S[j] == '?') j++;
                interval = j - start;
                if (interval % 2 == 1) {
                    for (int k = 0; k < interval; k++) {
                        if (k % 2 == 0) S[start + k] = 'o';
                        else S[start + k] = '.';
                    }
                }
                i = j;
            }
        }
        cout << S << endl;
    } else if (nNum > K) {
        cout << S << endl;
    }



    return 0;
}
