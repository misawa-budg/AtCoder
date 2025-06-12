#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    long long sum = accumulate(A.begin(), A.end(), 0LL);
    if (sum % 10 != 0) {
        cout << "No\n";
        return 0;
    }

    long long target = sum / 10;
    vector<int> B(2 * N);
    for (int i = 0; i < N; i++) {
        B[i] = A[i];
        B[i + N] = A[i];
    }

    int left = 0, right = 0;
    long long current_sum = 0;
    while (right < 2 * N) {
        current_sum += B[right];

        while (current_sum > target && left <= right) {
            current_sum -= B[left];
            left++;
        }

        if (current_sum == target) {
            cout << "Yes\n";
            return 0;
        }
        right++;
    }
    cout << "No\n";

    return 0;
}
