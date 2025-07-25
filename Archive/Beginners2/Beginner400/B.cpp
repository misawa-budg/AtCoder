#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;

    __int128 total = 0;
    __int128 element = 1;
    for (int i = 0; i <= M; i++) {
        total += element;
        element *= N;
        if (total > (__int128)1e9) {
            cout << "inf" << endl;
            return 0;
        }
    }
    cout << (long long)total << endl;


    return 0;
}
