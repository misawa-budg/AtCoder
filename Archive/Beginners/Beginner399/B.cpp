#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> points(N);
    for (int i = 0; i < N; i++) cin >> points[i];

    for (int i = 0; i < N; i++) {
        int rank = 1;
        for (int j = 0; j < N; j++) {
            if (points[j] > points[i]) {
                rank++;
            }
        }
        cout << rank << endl;
    }

    return 0;
}
