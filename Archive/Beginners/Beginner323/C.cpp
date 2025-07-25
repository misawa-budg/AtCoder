#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> problems(M); for (int i = 0; i < M; ++i) cin >> problems[i];
    vector<string> S(N); for (int i = 0; i < N; ++i) cin >> S[i];
    vector<int> points(N, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (S[i][j] == 'o') {
                points[i] += problems[j];
            }
        }
        points[i] += i + 1;
    }


    for (int i = 0; i < N; i++) {
        multiset<int, greater<int>> unsolved;
        for (int j = 0; j < M; j++) {
            if (S[i][j] == 'x') {
                unsolved.insert(problems[j]);
            }
        }

        int maxPoints = 0;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            maxPoints = max(maxPoints, points[j]);
        }

        int moreCount = 0;
        int point = points[i];
        while (point < maxPoints) {
            auto it = unsolved.begin();
            point += *it;
            unsolved.erase(it);
            moreCount++;
        }
        cout << moreCount << endl;
    }

    return 0;
}
