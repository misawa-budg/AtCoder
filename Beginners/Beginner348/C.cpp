#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    map<int, int> beans;
    for (int i = 0; i < N; i++) {
        int deliciousness, color;
        cin >> deliciousness >> color;
        if (beans.find(color) == beans.end()) {
            beans[color] = deliciousness;
        } else {
            beans[color] = min(beans[color], deliciousness);
        }
    }

    int maxDeliciousness = 0;
    for (auto it = beans.begin(); it != beans.end(); it++) {
        maxDeliciousness = max(maxDeliciousness, it->second);
    }
    cout << maxDeliciousness << endl;

    return 0;
}
