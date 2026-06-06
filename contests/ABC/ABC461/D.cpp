#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, K; cin >> H >> W >> K;

    vector<string> S(H); for (int i = 0; i < H; i++) cin >> S[i];

    long long result = 0;

    for (int top = 0; top < H; top++) {
        vector<int> colSum(W, 0);

        for (int bottom = top; bottom < H; bottom++) {
            for (int c = 0; c < W; c++) colSum[c] += S[bottom][c] - '0';

            unordered_map<int, long long> count;
            count[0] = 1;

            int sum = 0;
            for (int c = 0; c < W; c++) {
                sum += colSum[c];
                if (count.count(sum - K)) result += count[sum - K];
                count[sum]++;
            }
        }
    }

    cout << result << '\n';

    return 0;
}
