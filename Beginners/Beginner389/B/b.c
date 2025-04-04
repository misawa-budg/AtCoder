#include <stdio.h>

int main() {
    long x;
    scanf("%ld", &x);

    long factorial = 1;
    for (long i = 1; i <= x; i++) {
        factorial *= i;
        if (factorial == x) {
            printf("%ld\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
