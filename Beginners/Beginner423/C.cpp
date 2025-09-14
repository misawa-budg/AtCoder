#include <bits/stdc++.h>
using namespace std;

long long countClosed(int left, int right, const vector<int>& L)
{
    long long count = 0;
    for (int i = left; i <= right;  i++) {
        if (L[i] == 1) count++;
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, R; cin >> N >> R;
    vector<int> L(N + 1); for (int i = 1; i <= N; i++) cin >> L[i];

    int left = -1, right = -1;
    long long openCnt = 0;
    for (int i = 1; i <= N; i++) {
        if (L[i] == 0) {
            if (left == -1) left = i;
            right = i;
            openCnt++;
        }
    }
    if (openCnt == 0) {
        cout << 0 << endl;
        return 0;
    }

    // 閉じたドアは2回, 開いたドアは1回
    long long closed = countClosed(left, right, L);
    // 操作区間に移動する場合
    long long open_closed = 0;
    if (R < left - 1) open_closed = countClosed(R + 1, left - 1, L);
    else if (right < R) open_closed = countClosed(right + 1, R, L);
    else open_closed = 0;

    long long ans = openCnt + 2 * (closed + open_closed);
    cout << ans << endl;

    return 0;
}
