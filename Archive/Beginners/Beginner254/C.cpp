#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;
    vector<long long> A(N); for (int i = 0; i < N; i++) cin >> A[i];
    vector<long long> ideal = A;
    sort(ideal.begin(), ideal.end());

    vector<vector<long long>> Agroups(K), idealgroups(K);
    for (int i = 0; i < N; i++) {
        Agroups[i % K].push_back(A[i]);
        idealgroups[i % K].push_back(ideal[i]);
    }

    for (int i = 0; i < K; i++) {
        sort(Agroups[i].begin(), Agroups[i].end());

        if (Agroups[i] != idealgroups[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
