#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int ideal = 0, real = 0;
    vector<int> A(N), B(N);
    vector<string> S(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> S[i];
        ideal += A[i];
        if (S[i] == "keep") {
            real += B[i];
        } else {
            real += A[i];
        }
    }

    cout << (10000 - ideal) - (10000 - real) << '\n';

    return 0;
}
