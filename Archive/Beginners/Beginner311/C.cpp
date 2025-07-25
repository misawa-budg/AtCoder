#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> iToA(N + 1);
    for (int i = 1; i <= N; i++) {
        int to; cin >> to;
        iToA[i] = to;
    }

    vector<int> ans;
    vector<int> visited(N + 1, 0);

    int from = 1;
    while (!visited[from]) {
        visited[from] = ans.size() + 1;
        ans.push_back(from);
        from = iToA[from];
    }

    int start = visited[from] - 1;
    int M = ans.size() - start;
    cout << M << endl;
    for (int j = start; j < ans.size(); j++) {
        cout << ans[j] << " ";
    }
    cout << endl;



    return 0;
}
