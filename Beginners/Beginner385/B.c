#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int H, W, X, Y;
    scanf("%d %d %d %d", &H, &W, &X, &Y);

    char S[H][W+1];
    for (int i = 0; i < H; i++) {
        scanf("%s", S[i]);
    }

    char visited[H][W+1];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            visited[i][j] = 0;
        }
    }
    char T[10001];
    scanf("%s", T);

    int opLen = strlen(T);
    int x = X, y = Y;
    x--; y--;
    int count = 0;

    for (int i = 0; i < opLen; i++) {
        switch (T[i]) {
            case 'U':
                if (x-1 > 0 && S[x-1][y] != '#') {
                    x = x-1;
                }
                break;
            case 'D':
                if (x+1 < H && S[x+1][y] != '#') {
                    x = x+1;
                }
                break;
            case 'L':
                if (y-1 > 0 && S[x][y-1] != '#') {
                    y = y-1;
                }
                break;
            case 'R':
                if (y+1 < W && S[x][y+1] != '#') {
                    y = y+1;
                }
                break;
        }

        if (S[x][y] == '@' && visited[x][y] == 0) {
            visited[x][y] = 1;
            count++;
        }
    }

    printf("%d %d %d\n", x+1, y+1, count);

    return 0;
}
