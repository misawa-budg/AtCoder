#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    string S; cin >> S;
    vector<int> C(N); for(int i=0;i<N;i++) cin >> C[i];

    vector<deque<char>> dqs(M + 1);

    for (int i = 0; i < N; i++) {
        dqs[C[i]].push_back(S[i]);
    }

    for (int i = 1; i <= M; i++) {
        dqs[i].push_front(dqs[i].back());
        dqs[i].pop_back();
    }

    for (int i = 0; i < N; i++) {
        cout << dqs[C[i]].front();
        dqs[C[i]].pop_front();
    }
    cout << endl;

    return 0;
}