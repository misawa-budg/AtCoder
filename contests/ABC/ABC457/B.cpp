#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<vector<int>> A(N);

    for (int i = 0; i < N; i++) {
        int L; cin >> L;
        for (int j = 0; j < L; j++) {
            int num; cin >> num;
            A[i].push_back(num);
        }
    }

    int X, Y; cin >> X >> Y;
    cout << A[X-1][Y-1] << '\n';

    return 0;
}
