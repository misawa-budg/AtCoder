#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N; cin >> N;
    // 1_000_000_000以下: 10桁以下
    
    vector<string> parts;
    for (int i = 0; i < 30; i++) {
        long long value = 1LL << i;
        if (value <= 1000000000LL) parts.push_back(to_string(value));
    }

    vector<long long> result;
    stack<string> st;
    st.push("");

    while (!st.empty()) {
        string cur = st.top(); st.pop();

        if (!cur.empty()) result.push_back(stoll(cur));

        for (const string& p : parts) {
            string next = cur + p;
            if (next.length() > 10) continue;
            if (stoll(next) <= 1000000000LL) st.push(next);
        }
    }

    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());

    cout << result[N - 1] << '\n';

    return 0;
}
