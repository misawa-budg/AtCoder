#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, R;
    scanf("%d %d", &N, &R);

    for (int i = 0; i < N; i++) {
        int D, A;
        scanf("%d %d", &D, &A);

        int isValid = 0;
        if (1600 <= R && R <= 2799 && D == 1) {
            isValid = 1;
        } else if (1200 <= R && R <= 2399 && D == 2) {
            isValid = 1;
        }

        if (isValid) {
            R = R + A;
        }

    }

    printf("%d\n", R);

    return 0;
}
