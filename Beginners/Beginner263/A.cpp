#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> inputs(5);
    for (int i = 0; i < 5; ++i) {
        cin >> inputs[i];
    }
    sort(inputs.begin(), inputs.end());
    if ((inputs[0]==inputs[1]&&inputs[2]==inputs[4]) || (inputs[0]==inputs[2]&&inputs[3]==inputs[4])) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
