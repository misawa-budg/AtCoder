#include <stdio.h>

int main() {
    int N, T, A;
    scanf("%d %d %d", &N, &T, &A);

    int isFinished = 0;

    int th = N / 2 + 1;

    if(th <= T || th <= A) {
        isFinished = 1;
    }

    if(isFinished) {
        printf("Yes\n");
    }else {
        printf("No\n");
    }

    return 0;
}
