#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        v.push_back(num);
        int len = v.size();
        if (v[len-1] == v[len-2] && v[len-2] == v[len-3] && v[len-3] == v[len-4]) {
            v.resize(len - 4);
        }
    }
    cout << v.size() << '\n';

    return 0;
}
