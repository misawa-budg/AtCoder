#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> P(N); for (int i = 0; i < N; i++) cin >> P[i];
    vector<int> sign(N, 0);
    for (int i = 1; i < N - 1; i++) {
        if (P[i - 1] < P[i] && P[i] > P[i + 1]) sign[i] = 1;
        else if (P[i - 1] > P[i] && P[i] < P[i + 1]) sign[i] = -1;
    }

    vector<int> pos;
    pos.reserve(N + 2);
    pos.push_back(-1);
    for (int i = 0; i < N; ++i)
        if (sign[i] != 0) pos.push_back(i);
    pos.push_back(N);

    long long ans = 0;
    for (int k = 1; k < N; ++k) {
        int i = pos[k];
        int j = pos[k+1];
        if (sign[i] != 1) continue;

        long long left_choices  = i - pos[k-1];
        if (pos[k-1] == -1) left_choices--;
        long long right_choices = pos[k+2] - j;
        if (pos[k+2] == N) right_choices--;
        if (left_choices > 0 && right_choices > 0)
            ans += left_choices * right_choices;
    }
    cout << ans << endl;

    return 0;
}
