#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int level = 1;
    char carpet[2000][2000] = {0};
    carpet[0][0] = '#';
    for (int i = 0; i < N; i++) {
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                if (x == 1 && y == 1) {
                    for (int j = 0; j < pow(3, i); j++) {
                        for (int k = 0; k < pow(3, i); k++) {
                            carpet[x * level + j][y * level + k] = '.';
                        }
                    }
                } else {
                    for (int j = 0; j < pow(3, i); j++) {
                        for (int k = 0; k < pow(3, i); k++) {
                            carpet[x * level + j][y * level + k] = carpet[j][k];
                        }
                    }
                }
            }
        }
    }

    return 0;
}