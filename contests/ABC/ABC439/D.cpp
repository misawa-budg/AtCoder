#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N);
    map<int, int> left, right;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        right[A[i]]++;
    }

    long long ans = 0;
    for (int i = 0 ; i < N; i++) {
        right[A[i]]--;

        if (A[i] % 5 == 0) {
            int x = A[i] / 5;
            int seven = x * 7;
            int three = x * 3;

            ans += 1LL * right[three] * right[seven];
            ans += 1LL * left[three] * left[seven];
        }

        left[A[i]]++;
    }

    cout << ans << '\n';

    return 0;
}
