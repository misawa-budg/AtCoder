#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int count = 0;
    set<long long> s;
    // 入力上限での出力桁数は12
    for (string i = "1"; i.size() <= 12; i += "1") {
        for (string j = "1"; j.size() <= 12; j += "1") {
            for (string k = "1"; k.size() <= 12; k += "1") {
                s.insert(stoll(i) + stoll(j) + stoll(k));
            }
        }
    }

    for (auto i : s) {
        count++;
        if (count == N) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}
