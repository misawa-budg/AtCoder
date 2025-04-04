#include <iostream>

using namespace std;

int main() {
    long x;
    cin >> x;
    long factorial = 1;
    for (long i = 1; i <= x; i++) {
        factorial *= i;
        if (factorial == x) {
            cout << i << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}
