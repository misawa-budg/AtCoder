#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int R;
    scanf("%d", &R);

    int goal = (R / 100 + 1) * 100;
    printf("%d\n", goal - R);

    return 0;
}
