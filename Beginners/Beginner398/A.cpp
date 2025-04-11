#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    char ans[N + 1];
    int isEvenLength = (N % 2 == 0) ? 1 : 0;
    for (int i = 0; i < N; i++) {
        if (isEvenLength && (i == N / 2 - 1 || i == N / 2)) {
            ans[i] = '=';
        } else if (!isEvenLength && i == N / 2) {
            ans[i] = '=';
        } else {
            ans[i] = '-';
        }
    }
    ans[N] = '\0';

    cout << ans << endl;

    return 0;
}

// if (n%2 == 0){
//     int c = (n-2)/2;
//     cout << string(c,'-') + "==" + string(c,'-') << endl;
//     }else{
//     int c = (n-1)/2;
//     cout << string(c,'-') + "=" + string(c,'-') << endl;
// }
