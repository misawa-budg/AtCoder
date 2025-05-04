#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M; cin >> M;
    vector<int> D(M); for (int i = 0; i < M; i++) cin >> D[i];

    int sum = accumulate(D.begin(), D.end(), 0);
    int middle = (sum + 1) / 2;

    int i;
    for (i = 0; i < M; i++) {
        if (D[i] < middle) {
            middle -= D[i];
        } else {
            break;
        }
    }
    cout << i + 1 << " " << middle << endl;

    return 0;
}
