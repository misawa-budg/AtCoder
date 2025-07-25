#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char table[8][9];
    int canPut[8][8];
    int count = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            canPut[i][j] = 1;
        }
    }
    for (int i = 0; i < 8; i++) {
        scanf("%s", table[i]);
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (table[i][j] == '#') {
                for (int k = 0; k < 8; k++) {
                    canPut[i][k] = 0;
                }
                for (int k = 0; k < 8; k++) {
                    canPut[k][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (canPut[i][j] == 1) count++;
        }
    }

    printf("%d\n", count);

    return 0;

}
