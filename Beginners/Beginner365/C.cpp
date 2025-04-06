#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long M;
    cin >> N >> M;

    vector<long> transportationExpenses(N);
    for (int i = 0; i < N; i++) {
        cin >> transportationExpenses[i];
    }

    long long sum = accumulate(transportationExpenses.begin(), transportationExpenses.end(), 0LL);
    if (sum <= M) {
        cout << "infinite" << endl;
        return 0;
    }

    long l = 0, r = 2e14;
    while (abs(r - l) > 1) {
        long mid = (l + r) / 2;
        long total = 0;
        for (auto expense : transportationExpenses) {
            total += min(expense, mid);
        }
        if (total <= M) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l << endl;

    return 0;
}
