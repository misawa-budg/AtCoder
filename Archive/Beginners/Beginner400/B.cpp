#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    long long sum = 0;
    long long num = 1;
    for (int i = 0; i <= M; i++) {
        sum += num;
        if (sum > 1000000000) {
            cout << "inf" << endl;
            return 0;
        }
        num *= N;
    }

    cout << sum << endl;

    return 0;
}
