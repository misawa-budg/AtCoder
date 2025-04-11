#include <bits/stdc++.h>
using namespace std;

struct Card {
    int strength;
    int cost;
    int index;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<Card> cards(N);
    for (int i = 0; i < N; i++) {
        cin >> cards[i].strength >> cards[i].cost;
        cards[i].index = i + 1;
    }

    sort(cards.begin(), cards.end(), [](const Card &a, const Card &b) {
        return a.cost < b.cost;
    });

    vector<int> ans;
    int pivot = 0;
    for (int i = 0; i < N; i++) {
        if (cards[i].strength > pivot) {
            pivot = cards[i].strength;
            ans.push_back(cards[i].index);
        }
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
    }

    return 0;
}
