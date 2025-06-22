#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;
    vector<int> X(Q); for (int i = 0; i < Q; i++) cin >> X[i];

    vector<int> balls(N + 1); // ball[i] = i はi番目のボールの整数
    map<int, int> ballIndex;
    for (int i = 0; i < N; i++) {
        balls[i] = i + 1;
        ballIndex[i + 1] = i;
    }

    for (int i = 0; i < Q; i++) {
        int target = X[i];

        int idx = ballIndex[target];
        int swapIdx = idx + 1;
        if (idx == N - 1) swapIdx = idx - 1;

        swap(balls[idx], balls[swapIdx]);
        ballIndex[balls[idx]] = idx;
        ballIndex[balls[swapIdx]] = swapIdx;
    }

    for (int i = 0; i < N; i++) {
        cout << balls[i] << " ";
    }
    cout << endl;

    return 0;
}
