#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M; cin >> N >> M;
    vector<pair<long long, long long>> bottles(M);
    for (int i = 0; i < M; i++) {
        long long A, B; cin >> A >> B;
        bottles[i] = {A - B, A}; // diff, required
    }

    sort(bottles.begin(), bottles.end());
    long long seals = 0;
    long long remain = N;
    while (true) {
        int best = -1;
        for (int i = 0; i < M; i++) {
            if (remain >= bottles[i].second) {
                best = i;
                break;
            }
        }
        if (best == -1) break;
        long long diff = bottles[best].first;
        long long required = bottles[best].second;
        long long time = (remain - required) / diff + 1;

        seals += time;
        remain -= time * diff;
    }
    cout << seals << '\n';

    return 0;
}
