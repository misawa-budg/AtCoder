#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    string T = S;
    for (int i = 0; i < N; i++){
        if (T[i] == '?') {
            bool adjacentToO = false;
            if (i - 1 >= 0 && S[i - 1] == 'o') {
                adjacentToO = true;
            }
            if (i + 1 < N && S[i + 1] == 'o') {
                adjacentToO = true;
            }
            if (adjacentToO) {
                T[i] = '.';
            }
        }
    }

    int countO = 0;
    for (char c : T) {
        if (c == 'o') countO++;
    }

    if (countO == K) {
        for (int i = 0; i < N; i++){
            if (T[i] == '?') T[i] = '.';
        }
        cout << T << "\n";
        return 0;
    }

    string greedy = T;
    for (int i = 0; i < N; i++){
        if (greedy[i] == '?') {
            if (i == 0 || greedy[i - 1] != 'o') {
                greedy[i] = 'o';
            } else {
                greedy[i] = '.';
            }
        }
    }
    int M = 0;
    for (char c : greedy) {
        if (c == 'o') M++;
    }

    if (M > K) {
        cout << T << "\n";
        return 0;
    }

    string ans = T;
    int i = 0;
    while (i < N) {
        if (T[i] == '?') {
            int j = i;
            while (j < N && T[j] == '?') j++;
            int len = j - i;
            if (len % 2 == 1) {
                for (int k = 0; k < len; k++) {
                    if (k % 2 == 0)
                        ans[i + k] = 'o';
                    else
                        ans[i + k] = '.';
                }
            }
            i = j;
        } else {
            i++;
        }
    }

    cout << ans << "\n";
    return 0;
}
