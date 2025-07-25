#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int Q;
    cin >> Q;
    vector<int> cards(100);
    for (int i = 0; i < Q; i++) {
        int op, num;
        cin >> op;
        if (op == 1) {
            cin >> num;

            cards.push_back(num);
        } else {
            num = cards.back();
            cards.pop_back();
            cout << num << endl;
        }
    }

    return 0;
}
