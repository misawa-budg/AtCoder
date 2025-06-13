#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;
    const int MAX_VAL = 5000;
    vector<vector<int>> cumulative(5000+1, vector<int>(5000+1, 0));

    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        cumulative[a][b]++;
    }

    for (int i = 1; i <= MAX_VAL; i++) {
        for (int j = 1; j <= MAX_VAL; j++) {
            cumulative[i][j] += cumulative[i-1][j] + cumulative[i][j-1] - cumulative[i-1][j-1];
        }
    }

    int students = 0;
    for (int h = 1; h <= MAX_VAL; h++) {
        for (int w = 1; w <= MAX_VAL; w++) {
            int hMin = max(1, h - K);
            int wMin = max(1, w - K);

            int count = cumulative[h][w] - cumulative[hMin-1][w] - cumulative[h][wMin-1] + cumulative[hMin-1][wMin-1];
            students = max(students, count);
        }
    }

    cout << students << endl;
    return 0;
}
