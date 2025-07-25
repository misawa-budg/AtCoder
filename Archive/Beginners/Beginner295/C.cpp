#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];
    map<int, int> socksCount;
    for (int i = 0; i < N; i++) {
        socksCount[A[i]]++;
    }

    int pairs = 0;
    for (const auto& [sock, count] : socksCount) {
        pairs += count / 2;
    }

    cout << pairs << endl;

    return 0;
}
