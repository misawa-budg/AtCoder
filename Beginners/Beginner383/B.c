#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int x;
    int y;
}coordinate;

int main() {
    int H, W, D;
    scanf("%d %d %d", &H, &W, &D);

    char office[H][W+1];
    coordinate index[100];
    int amount = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            scanf(" %c", &office[i][j]);
            if (office[i][j] == '.') {
                index[amount].x = j;
                index[amount].y = i;
                amount++;
            }
        }
    }

    int isHumid[H][W];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            isHumid[i][j] = 0;
        }
    }

    int count = 0;
    int countMax = 0;

    for (int i = 0; i < amount - 1; i++) {
    for (int j = i + 1; j < amount; j++) {
        coordinate humid1 = index[i];
        coordinate humid2 = index[j];
        isHumid[humid1.y][humid1.x] = 1;
        isHumid[humid2.y][humid2.x] = 1;

        for (int dy = -D; dy <= D; dy++) {
            for (int dx = -D; dx <= D; dx++) {
                int ny = humid1.y + dy;
                int nx = humid1.x + dx;
                if (0 <= ny && ny < H && 0 <= nx && nx < W) {
                    if (abs(dy) + abs(dx) <= D && office[ny][nx] == '.') {
                        isHumid[ny][nx] = 1;
                    }
                }
            }
        }


        for (int dy = -D; dy <= D; dy++) {
            for (int dx = -D; dx <= D; dx++) {
                int ny = humid2.y + dy;
                int nx = humid2.x + dx;
                if (0 <= ny && ny < H && 0 <= nx && nx < W) {
                    if (abs(dy) + abs(dx) <= D && office[ny][nx] == '.') {
                        isHumid[ny][nx] = 1;
                    }
                }
            }
        }

        int count = 0;
        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {
                if (isHumid[y][x] == 1) count++;
            }
        }

        if (count > countMax) countMax = count;

        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {
                isHumid[y][x] = 0;
            }
        }
    }
}


    printf("%d\n", countMax);

    return 0;
}
