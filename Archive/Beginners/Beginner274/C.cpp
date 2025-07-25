#include <bits/stdc++.h>
#include <bit>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> depth(2 * N + 2, 0); depth[0] = 1;

    for (int i = 0; i < N; i++) {
        int parent = A[i];
        int child1 = 2 * (i + 1);
        int child2 = 2 * (i + 1) + 1;

        depth[child1] = depth[parent] + 1;
        depth[child2] = depth[parent] + 1;
    }

    for (int i = 1; i < depth.size(); i++) {
        cout << depth[i] << endl;
    }

    return 0;
}
