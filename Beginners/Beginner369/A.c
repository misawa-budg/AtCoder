#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int A, B;
    scanf("%d %d", &A, &B);

    if(A==B) {
        printf("1\n");
    } else if((A+B)%2 == 0) {
        printf("3\n");
    } else {
        printf("2\n");
    }

}
