#include <bits/stdc++.h>
using namespace std;

void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    int index = 0;
    vector<pair<int, int>> swapLogs;
    vector<int> ans(A);
    while (index < N) {
        int number = ans[index];
        if (number == index + 1) {
            index++;
        } else {
            int swapIndex = number - 1;
            swapLogs.push_back({index + 1, swapIndex + 1});
            swap(ans[index], ans[swapIndex]);
        }
    }

    cout << swapLogs.size() << endl;
    for (const auto& swapLog : swapLogs) {
        cout << swapLog.first << " " << swapLog.second << endl;
    }

    return 0;
}
