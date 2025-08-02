#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    multiset<int> A;
    vector<int> B(M);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        A.insert(x);
    }
    for (int i = 0; i < M; i++) cin >> B[i];

    for (int i = 0; i < M; i++) {
        if (A.find(B[i]) != A.end()) {
            A.erase(A.find(B[i]));
        }
    }

    for (const auto& x : A) {
        cout << x << " ";
    }
    cout << endl;


    return 0;
}
