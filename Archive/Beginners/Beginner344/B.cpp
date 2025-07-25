#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> A;
    int input;
    while(cin >> input) {
        A.push_back(input);
        if (input == 0) break;
    }

    for (auto it = A.rbegin(); it != A.rend(); it++) {
        cout << *it << endl;
    }

    return 0;
}
