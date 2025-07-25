#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    int can = 0;

    if (A == B && B == C) {
        printf("Yes\n");
        return 0;
    }

    int max = A;
    if (B > max) {
        max = B;
    }
    if (C > max) {
        max = C;
    }

    if (max == A) {
        if (B + C == A) {
            can = 1;
        }
    } else if (max == B) {
        if (A + C == B) {
            can = 1;
        }
    } else {
        if (A + B == C) {
            can = 1;
        }
    }

    if (can) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
