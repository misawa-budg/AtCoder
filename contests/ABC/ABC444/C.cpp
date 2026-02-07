#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N; cin >> N;
    long long biggest = 0;
    vector<long long> A(N); for (int i = 0; i < N; i++) {
        cin >> A[i];
        biggest = max(biggest, A[i]);
    }

    sort(A.begin(), A.end());

    if (N % 2 == 1) {
        cout << biggest << '\n';
    } else {
        int left = 0, right = N - 1;
        if (A[right] == biggest) while (right >= 0 && A[right] == biggest) right--;
        bool ok = true;
        while (left < right) {
            if (A[left] + A[right] != biggest) {
                ok = false;
                break;
            }
            left++; right--;
        }
        if (left == right) ok = false;
        if (ok) cout << biggest << ' ';

        left = 0; right = N - 1;
        long long target = A[left] + A[right];
        ok = true;
        while (left < right) {
            if (A[left] + A[right] != target) {
                ok = false;
                break;
            }
            left++; right--;
        }
        if (ok) cout << target;
    }
    cout << '\n';

    return 0;
}
