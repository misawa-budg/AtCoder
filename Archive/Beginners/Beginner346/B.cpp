#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int W, B; cin >> W >> B;
    string S = "wbwbwwbwbwbw";
    vector<pair<int, int>> colorCounts(1000);
    colorCounts[0] = {0, 0};
    for (int i = 1; i < colorCounts.size(); i++) {
        if (S[i % S.size()] == 'w') {
            colorCounts[i] = {colorCounts[i - 1].first + 1, colorCounts[i - 1].second};
        } else {
            colorCounts[i] = {colorCounts[i - 1].first, colorCounts[i - 1].second + 1};
        }
    }

    bool isExist = false;
    for (int i = 0; i < colorCounts.size() - 1; i++) {
        for (int j = i + 1; j < colorCounts.size(); j++) {
            int w = colorCounts[j].first - colorCounts[i].first;
            int b = colorCounts[j].second - colorCounts[i].second;
            if (w == W && b == B) {
                isExist = true;
                break;
            }
        }
    }

    if (isExist) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
