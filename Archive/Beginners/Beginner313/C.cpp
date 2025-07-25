#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];
    long long sum = accumulate(A.begin(), A.end(), 0LL);

    long long floor = sum / N;
    long long ceil = (sum + N - 1) / N;
    long long inc = 0, dec = 0;

    for (int a : A) {
        if (a < floor) inc += floor - a;
        else if (a > ceil) dec += a - ceil;
    }

    cout << max(inc, dec) << endl;

    return 0;
}
