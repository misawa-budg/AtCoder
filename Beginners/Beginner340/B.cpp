#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q; cin >> Q;
    vector<int> A;
    for (int i = 0; i < Q; i++) {
        int query, num; cin >> query >> num;
        if (query == 1) {
            A.push_back(num);
        } else {
            cout << A[A.size() - num] << endl;
        }
    }

    return 0;
}
