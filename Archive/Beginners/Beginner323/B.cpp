#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    vector<pair<int, int>> points_index(N);
    for (int i = 1; i <= N; i++) {
        points_index[i - 1].first = 0;
        points_index[i - 1].second = i;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c = S[i][j];
            if (c == 'o') {
                points_index[i].first++;
            }
        }
    }

    sort(points_index.begin(), points_index.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.first != b.first) {
            return a.first > b.first;
        } else {
            return a.second < b.second;
        }
    });

    for (int i = 0; i < N; i++) {
        cout << points_index[i].second << " ";
    }
    cout << endl;

    return 0;
}
