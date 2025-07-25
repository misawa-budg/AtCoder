#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main()
{
    char S[101];
    scanf("%s", S);
    int A[100], count = 0;
    for (int i = 0; i < 100; i++) {
        A[i] = -1;
    }
    int amount = 0;
    for (int i = 1; S[i] != '\0'; i++) {
        if (S[i] == '-') {
            count++;
        } else {
            A[amount++] = count;
            count = 0;
        }
    }

    for (int i = 0; i < 100; i++) {
        if (A[i] == -1) break;
        if (i) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");

    return 0;

}
