#include <stdio.h>

int main() {
    int M;
    scanf("%d", &M);

    int powers[11];
    for (int i = 0; i <= 10; i++) {
        int power = 1;
        for (int j = 0; j < i; j++) {
            power *= 3;
        }
        powers[i] = power;
    }

    int A[20];
    int N = 0;
    int M_remaining = M;

    while (M_remaining > 0) {
        int found = 0;
        for (int i = 10; i >= 0; i--) {
            if (powers[i] <= M_remaining) {
                M_remaining -= powers[i];
                A[N++] = i;
                found = 1;
                break;
            }
        }
        if (!found) {
            break;
        }
    }

    printf("%d\n", N);
    for (int i = 0; i < N; i++) {
        printf("%d", A[i]);
        if (i != N - 1) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
