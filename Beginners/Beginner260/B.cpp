#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X, Y, Z; cin >> N >> X >> Y >> Z;
    vector<pair<int, int>> A(N), B(N), C(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i + 1;
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i].first;
        B[i].second = i + 1;
    }
    for (int i = 0; i < N; i++) {
        C[i].first = A[i].first + B[i].first;
        C[i].second = i + 1;
    }

    auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first != b.first) {
            return a.first > b.first; // Sort in descending order
        }
        return a.second < b.second;
    };
    sort(A.begin(), A.end(), cmp);
    sort(B.begin(), B.end(), cmp);
    sort(C.begin(), C.end(), cmp);

    vector<int> pass(N + 1, 0);
    for (int i = 0; i < X; i++) {
        pass[A[i].second] = 1;
    }
    for (int i = 0, passed = 0; i < N && passed < Y; i++) {
        if (pass[B[i].second] == 0) {
            pass[B[i].second] = 1;
            passed++;
        }
    }
    for (int i = 0, passed = 0; i < N && passed < Z; i++) {
        if (pass[C[i].second] == 0) {
            pass[C[i].second] = 1;
            passed++;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (pass[i]) {
            cout << i << '\n';
        }
    }

    return 0;
}
