#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> C(N); for (int i = 0; i < N; i++) cin >> C[i];

    vector<int> left(N, -1), right(N, -1);
    
    for (int i = 1; i < N; i++) {
        if (C[i - 1] == C[i]) left[i] = left[i - 1];
        else left[i] = i - 1;
    }

    for (int i = N - 2; i >= 0; i--) {
        if (C[i + 1] == C[i]) right[i] = right[i + 1];
        else right[i] = i + 1;
    }

    for (int i = 0; i < N; i++) {
        int nearest = INT_MAX;
        if (left[i] != -1) nearest = min(nearest, i - left[i]);
        if (right[i] != -1) nearest = min(nearest, right[i] - i);

        cout << nearest << ' ';
    }

    return 0;
}
