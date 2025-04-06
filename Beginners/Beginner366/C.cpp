#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    int Q;
    cin >> Q;

    vector<int> numbers(1000000);
    int variety = 0;
    for (int i = 0; i < Q; i++) {
        int query;
        cin >> query;

        if (query == 1) {
            int x;
            cin >> x;
            x--;

            numbers[x]++;
            if (numbers[x] == 1) variety++;
        } else if (query == 2) {
            int x;
            cin >> x;
            x--;

            numbers[x]--;
            if (numbers[x] == 0) variety--;
        } else {
            cout << variety << endl;
        }
    }

    return 0;
}
