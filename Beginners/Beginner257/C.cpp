#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string S; cin >> S;
    vector<pair<int, char>> people(N);
    for (int i = 0; i < N; i++) {
        cin >> people[i].first;
        people[i].second = S[i];
    }
    sort(people.begin(), people.end());

    long long correct = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '1') correct++;
    }

    long long ans = correct;
    for (int i = 0; i < N; i++) {
        if (people[i].second == '0') {
            correct++;
        } else {
            correct--;
        }

        if (i < N - 1 && people[i].first == people[i + 1].first) continue;
        ans = max(ans, correct);
    }

    cout << ans << '\n';

    return 0;
}
