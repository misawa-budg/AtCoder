#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, A;
    scanf("%d %d", &N, &A);
    int *T = (int *)malloc(sizeof(int) * N);
    int sum = 0;

    for(int i = 0; i < N; i++) {
        scanf("%d", &T[i]);
    }

    for(int i = 0; i < N; i++) {
        if(sum < T[i]) {
            sum += T[i] - sum;
        }
        sum += A;
        printf("%d\n", sum);
    }

    free(T);
    return 0;
}
