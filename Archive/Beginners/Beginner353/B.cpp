#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    int index = 0, ans = 0, empty = K, groups = N;
    while (groups > 0 && index < N) {
        if (A[index] > empty) {
            ans++;
            empty = K;
        } else {
            empty -= A[index];
            groups--;
            index++;
        }
    }
    ans++;

    cout << ans << endl;

    return 0;
}
