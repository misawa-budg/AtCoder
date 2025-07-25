#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        A[i] = input - 1;
    }

    int front = -1;
    vector<int> B(N, N);
    for (int i = 0; i < N; i++) {
        if (A[i] < 0) {
            front = i;
        } else {
            B[A[i]] = i;
        }
    }

    while (front < N) {
        cout << front + 1 << " ";
        front = B[front];
    }
    cout << endl;

    return 0;
}
