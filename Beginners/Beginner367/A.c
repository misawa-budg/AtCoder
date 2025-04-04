#include <stdio.h>
#include <string.h>

int main() {
    int A, B, C;

    scanf("%d %d %d", &A, &B, &C);

    int canShout = 1;

    if(C < B) {
        B -= 24;
    }

    if(B < A && A < C) {
        canShout = 0;
    }

    if(canShout) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }


    return 0;
}
