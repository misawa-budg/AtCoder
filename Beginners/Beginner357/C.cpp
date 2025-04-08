#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    char ans[1000][1000];

    int level = 1;
    ans[0][0] = '#';
    for (int i = 0; i < N; i++) {
        for (int y = 0; y < 3; y++) {
            for (int x = 0; x < 3; x++) {
                if (y == 0 && x == 0) continue;
                if (y == 1 && x == 1) {
                    for (int j = 0; j < level; j++) {
                        for (int k = 0; k < level; k++) {
                            ans[level + j][level + k] = '.';
                        }
                    }
                } else {
                    for (int j = 0; j < level; j++) {
                        for (int k = 0; k < level; k++) {
                            ans[y * level + j][x * level + k] = ans[j][k];
                        }
                    }
                }
            }
        }
        level *= 3;
    }

    int range = pow(3, N);
    for (int i = 0; i < range; i++) {
        for (int j = 0; j < range; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}
