#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<pair<int, int>> students(N);
    for (int i = 0; i < N; i++) {
        cin >> students[i].first >> students[i].second;
    }

    vector<int> cumulative1(N + 1, 0);
    vector<int> cumulative2(N + 1, 0);
    for (int i = 0; i < N; i++) {
        if (students[i].first == 1) {
            cumulative1[i + 1] = cumulative1[i] + students[i].second;
            cumulative2[i + 1] = cumulative2[i];
        } else {
            cumulative2[i + 1] = cumulative2[i] + students[i].second;
            cumulative1[i + 1] = cumulative1[i];
        }
    }

    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int l, r; cin >> l >> r; l--; r--;

        cout << cumulative1[r + 1] - cumulative1[l] << ' '
             << cumulative2[r + 1] - cumulative2[l] << '\n';

    }


    return 0;
}
