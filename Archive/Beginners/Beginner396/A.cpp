#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N - 2; i++) {
        int num = A[i];
        if (A[i+1] == A[i] && A[i+2] == A[i]) {
            cout << "Yes" << "\n";
            return 0;
        }
    }

    cout << "No" << "\n";

    return 0;
}
