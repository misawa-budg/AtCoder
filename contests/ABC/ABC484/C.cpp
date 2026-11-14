#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    if (A == B) {
        cout << "Yes\n";
        return 0;
    }

    int l = 0, r = N - 1;
    while (A[l] == B[l]) l++;
    while (A[r] == B[r]) r--;

    vector<int> C = A;
    int x = C[l];
    C.erase(C.begin() + l);
    C.insert(C.begin() + r, x);

    if (C == B) {
        cout << "Yes\n";
        return 0;
    }

    C = A;
    x = C[r];
    C.erase(C.begin() + r);
    C.insert(C.begin() + l, x);

    cout << (C == B ? "Yes\n" : "No\n");

    return 0;
}
