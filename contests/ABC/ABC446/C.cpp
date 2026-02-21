#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N, D; cin >> N >> D;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        for (int i = 0; i < N; i++) cin >> B[i];
        
        deque<pair<long long, int>> eggs;

        for (int i = 0; i < N; i++) {
            eggs.emplace_back(A[i], i);

            long long need = B[i];
            while (need > 0) {
                auto &front = eggs.front();
                long long take = min(need, front.first);
                front.first -= take;
                need -= take;
                if (front.first == 0) eggs.pop_front();
            }

            while (!eggs.empty() && i - eggs.front().second >= D) {
                eggs.pop_front();
            }
        }
        
        long long total = 0;
        for (auto &egg : eggs) total += egg.first;
        cout << total << '\n';

    }

    return 0;
}
