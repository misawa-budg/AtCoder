#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    map<int, int> freq;
    long long count = 0;
    // Ai + i = j - Aj
    for (int j = 0; j < N; j++) {
        int target = j - A[j];
        if (freq.find(target) != freq.end()) {
            count += freq[target];
        }
        freq[A[j] + j]++;
    }
    cout << count << endl;

    return 0;
}
