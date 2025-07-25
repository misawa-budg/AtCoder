#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> numbers(N);
    for (int i = 0; i < N; i++) cin >> numbers[i];
    // set<int> varietiesLeft;
    // set<int> varietiesRight;

    // int leftCount = 0, rightCount = 0, ans = 0;
    // for (int i = 1; i < N; i++) {
    //     varietiesLeft.clear();
    //     varietiesRight.clear();
    //     for (int j = 0; j < i; j++) {
    //         varietiesLeft.insert(numbers[j]);
    //     }
    //     for (int j = i; j < N; j++) {
    //         varietiesRight.insert(numbers[j]);
    //     }
    //     leftCount = varietiesLeft.size();
    //     rightCount = varietiesRight.size();

    //     ans = max(ans, leftCount + rightCount);
    // }

    // 下記のプログラムも改善可能
    // vector<int> v(N + 1, 0)で1/0管理

    // varieties(N ... )にして詰まった
    vector<vector<int>> varieties(2, vector<int>(N, 0));
    unordered_set<int> seen;
    for (int i = 0; i < N; i++) {
        seen.insert(numbers[i]);
        varieties[0][i] = seen.size();
    }
    seen.clear();
    for (int i = N - 1; i >= 0; i--) {
        seen.insert(numbers[i]);
        varieties[1][i] = seen.size();
    }

    int ans = 0, kindsTotal;
    for (int i = 0; i < N - 1; i++) {
        kindsTotal = varieties[0][i] + varieties[1][i + 1];
        ans = max(ans, kindsTotal);
    }

    cout << ans << endl;

    return 0;
}
