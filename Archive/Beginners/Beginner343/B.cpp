#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<vector<int>> adjacencyMatrix(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> adjacencyMatrix[i][j];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (adjacencyMatrix[i][j] == 1) {
                cout << j + 1 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
