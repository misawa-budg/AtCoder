#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> count(M);
    vector<vector<int>> foodToMeal(N);
    vector<int> B(N);

    for (int i = 0; i < M; i++) {
        int K; cin >> K;
        count[i] = K;
        for (int j = 0; j < K; j++) {
            int meal; cin >> meal; meal--;
            foodToMeal[meal].push_back(i);
        }
    }

    for (int i = 0; i < N; i++) {
        int food; cin >> food; food--;
        B[i] = food;
    }

    long long ans = 0;
    for (int i = 0; i < N; i++) {

        for (auto meal : foodToMeal[B[i]]) {
            count[meal]--;
            if (count[meal] == 0) ans++;
        }

        cout << ans << endl;
    }

    return 0;
}
