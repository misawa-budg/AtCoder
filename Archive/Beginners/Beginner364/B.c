#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int H, W;
    scanf("%d %d", &H, &W);

    int Si, Sj;
    scanf("%d %d", &Si, &Sj);
    Si--; Sj--;

    char C[50][51];
    for (int i = 0; i < H; i++) {
        scanf("%s", C[i]);
    }

    char op[51];
    scanf("%s", op);
    int oplen = strlen(op);

    for (int i = 0; i < oplen; i++) {
        switch (op[i]) {
            case 'L':
                if (0 <= Sj - 1 && C[Si][Sj - 1] == '.') {
                    Sj -= 1;
                }
                break;
            case 'R':
                if (Sj + 1 < W && C[Si][Sj + 1] == '.') {
                    Sj += 1;
                }
                break;
            case 'U':
                if (0 <= Si - 1 && C[Si - 1][Sj] == '.') {
                    Si -= 1;
                }
                break;
            case 'D':
                if (Si + 1 < H && C[Si + 1][Sj] == '.') {
                    Si += 1;
                }
                break;
        }
    }

    printf("%d %d", Si + 1, Sj + 1);

    return 0;
}
