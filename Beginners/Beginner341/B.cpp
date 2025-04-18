#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<pair<long long, long long>> rates(N - 1);
    for (int i = 0; i < N - 1; i++) {
        long long a, b; cin >> a >> b;
        rates[i] = {a, b};
    }

    for (int i = 0; i < N - 1; i++) {
        long long remain = A[i];
        long long count = remain / rates[i].first;
        remain -= count * rates[i].first;
        A[i + 1] += count * rates[i].second;
    }

    cout << A[N - 1] << endl;


    return 0;
}
