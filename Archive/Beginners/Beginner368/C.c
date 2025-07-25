#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    int *H = (int *)malloc(N * sizeof(int));
    for(int i = 0; i < N; i++) {
        scanf("%d", &H[i]);
    }

    long T = 0;
    for(int i = 0; i < N; i++) {
        int enemy = H[i];

        if (enemy > 250) {
            int full_reductions = enemy / 250;
            T += full_reductions * 150;
            enemy -= full_reductions * 250;
        }

        while (enemy > 0) {
            T++;
            enemy -= (T % 3 == 0) ? 3 : 1;
        }
    }

    printf("%ld\n", T);

    free(H);

    return 0;

}
