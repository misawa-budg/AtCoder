#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int N, D;
    scanf("%d %d", &N, &D);
    char S[N+1];
    scanf("%s", S);

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '@') {
            count++;
        }
    }
    int empty = N - count;

    printf("%d\n", empty + D);

    return 0;
}
