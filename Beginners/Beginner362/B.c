#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int xa, ya, xb, yb, xc, yc;
    scanf("%d %d %d %d %d %d", &xa, &ya, &xb, &yb, &xc, &yc);

    int A = (xb-xa)*(xb-xa) + (yb-ya)*(yb-ya);
    int B = (xc-xb)*(xc-xb) + (yc-yb)*(yc-yb);
    int C = (xa-xc)*(xa-xc) + (ya-yc)*(ya-yc);

    int isRight = 0;

    if(A == B + C || B == C + A || C == A + B) isRight = 1;

    (isRight==1) ? printf("Yes\n") : printf("No\n");

    return 0;
}
