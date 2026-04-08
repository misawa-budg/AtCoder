#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A;
    
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        A.push_back(a);
        int size = A.size();

        if (size >= 4
         && A[size-1] == A[size-2]
         && A[size-2] == A[size-3]
         && A[size-3] == A[size-4]) {
            A.resize(size-4);
         }
    }

    cout << A.size() << '\n';

    return 0;
}
