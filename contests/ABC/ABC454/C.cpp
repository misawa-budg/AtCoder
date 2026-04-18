#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> A(M), B(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
    }

    map<int, vector<int>> exchanges;
    for (int i = 0; i < M; i++) {
        exchanges[A[i]].push_back(B[i]);
    }

    vector<bool> available(N, false);
    available[0] = true;

    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int item = q.front(); q.pop();

        for (int get : exchanges[item]) {
            if (available[get]) continue;
            available[get] = true;
            q.push(get);
        }
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (available[i]) count++;
    }

    cout << count << '\n';

    return 0;
}
