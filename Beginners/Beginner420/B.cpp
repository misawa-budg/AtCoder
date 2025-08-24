#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<string> S(N); for (int i = 0; i < N; i++) cin >> S[i];

    vector<int> points(N, 0);
    for (int i = 0; i < M; i++) {
        int one = 0, zero = 0;
        for (int j = 0; j < N; j++) {
            if (S[j][i] == '0') zero++;
            else one++;
        }

        if (one == 0 || zero == 0) {
            for (int j = 0; j < N; j++) points[j]++;
        } else if (zero < one) {
            for (int j = 0; j < N; j++) {
                if (S[j][i] == '0') points[j]++;
            }
        } else {
            for (int j = 0; j < N; j++) {
                if (S[j][i] == '1') points[j]++;
            }
        }
    }

    int highest = *max_element(points.begin(), points.end());
    for (int i = 0; i < N; i++) {
        if (points[i] == highest) cout << i + 1 << " ";
    }
    cout << endl;

    return 0;
}
