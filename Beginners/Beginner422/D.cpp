#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    long long K; cin >> K;

    // floor(K/2), K - floor(K/2)で分割可能->再帰
    vector<long long> result(1 << N);
    function<void(int, int, int, long long)> dfs = [&](int n, int L, int R, long long K)
    {
        if (n == 0) {
            result[L] = K;
            return;
        }

        int half = (L + R) / 2;
        long long left = K / 2; // 左の和
        long long right = K - left; // 右の和(差0or1)
        dfs(n - 1, L, half, left);
        dfs(n - 1, half, R, right);
    };

    dfs(N, 0, 1 << N, K);

    if (K % (1LL << N) == 0) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }
    for (int i = 0; i < (1 << N); i++) {
        if (i) cout << " ";
        cout << result[i];
    }
    cout << endl;


    return 0;
}
