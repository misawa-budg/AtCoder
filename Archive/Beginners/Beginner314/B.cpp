#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<vector<int>> number_person(37);
    vector<int> betCounts(N + 1);
    for (int i = 0; i < N; i++) {
        int count; cin >> count;
        betCounts[i + 1] = count;
        for (int j = 0; j < count; j++) {
            int x; cin >> x;
            number_person[x].push_back(i + 1);
        }
    }
    int target; cin >> target;

    vector<pair<int, int>> result;
    for (int& i : number_person[target]) {
        result.push_back({betCounts[i], i});
    }
    if (result.empty()) {
        cout << 0 << endl;
        return 0;
    }
    sort(result.begin(), result.end());

    int least = result[0].first;
    vector<int> least_person;
    for (int i = 0; i < result.size(); i++) {
        if (result[i].first == least) {
            least_person.push_back(result[i].second);
        } else {
            break;
        }
    }
    
    cout << least_person.size() << endl;
    for (int i = 0; i < least_person.size(); i++) {
        cout << least_person[i];
        if (i != least_person.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}