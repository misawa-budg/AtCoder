#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(7 * N); for (int i = 0; i < 7 * N; ++i) cin >> A[i];

    for (int i = 0; i < 7 * N; i += 7) {
        int sum = 0;
        for (int j = i; j < i + 7; j++) {
            sum += A[j];
        }
        cout << sum << " ";
    }

    cout << endl;

    return 0;
}
