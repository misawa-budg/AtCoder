#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;

    vector<int> a;
    for (int i = 0; i < N; i++) a.push_back(0);
    for (int i = 0; i < M - N; i++) a.push_back(1);

    do {
        for (int i = 0; i < M; i++) {
            if (a[i] == 0) cout << i + 1 << ' ';
        }
        cout << '\n';
    } while (next_permutation(a.begin(), a.end()));

    return 0;
}
