#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A;

    int prev;
    cin >> prev;
    A.push_back(prev);

    for (int i = 1; i < N; ++i) {
        int curr; cin >> curr;

        if (curr > prev) {
            for (int j = prev + 1; j < curr; j++) {
                A.push_back(j);
            }
        } else if (curr < prev) {
            for(int j = prev - 1; j > curr; j--) {
                A.push_back(j);
            }
        }

        A.push_back(curr);
        prev = curr;
    }

    cout << A[0];
    for (size_t i = 1; i < A.size(); ++i) {
        cout << " " << A[i];
    }
    cout << endl;

    return 0;
}
